import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions, HTTPException, InternalServerError
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Ensure responses aren't cached
@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    stocks = db.execute("""SELECT SUM(shares) as totalshares, symbol FROM transactions WHERE
    user_id = ? GROUP BY symbol HAVING totalshares > 0""", session["user_id"])
    user_cash = db.execute("""SELECT cash FROM users WHERE id = ?""", session['user_id'])
    cash = user_cash[0]["cash"]
    total_cash = 0
    total_stocks = []
    for stock in stocks:
        temp_stock = lookup(stock['symbol'])
        total_stocks.append({
            'symbol': temp_stock['symbol'],
            'name': temp_stock['name'],
            'shares': stock['totalshares'],
            'price': temp_stock['price'],
            'total': stock['totalshares'] * temp_stock['price']
        })
        total_cash = total_cash + stock['totalshares'] * temp_stock['price']
        total_cash += cash
    return render_template("index.html", total_stocks=total_stocks, total_cash=total_cash, cash=cash)


@app.route("/addcash", methods=["GET", "POST"])
@login_required
def addcash():
    if request.method == "POST":
        cash_amount = int(request.form.get("cash"))
        if cash_amount < 0:
            return apology("cash must be a positive value", 400)
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", cash_amount, session["user_id"])
        flash("Amount updated")
        return redirect("/")
    if request.method == "GET":
        return render_template("addcash.html")


@app.route("/changepass", methods=["GET", "POST"])
@login_required
def changepass():
    if request.method == "POST":

        # Ensure username was submitted
        USERNAME = request.form.get("username")
        if not USERNAME:
            return apology("Please enter username!", 400)

        # AS user typed password for logging in so we are not checking it again just asking for new password
        # Ensure password was submitted
        NEW_PASS = request.form.get("newpass")
        if not NEW_PASS:
            return apology("Please enter new password", 400)

        try:
            session["user_id"] = db.execute("UPDATE users SET hash=:hash WHERE username=:username",
                                            username=USERNAME, hash=generate_password_hash(NEW_PASS))
        except:
            return apology("PLEASE ENTER CORRECT USERNAME", 400)
        flash("Password changed successfully")
        return redirect("/")

    if request.method == "GET":
        return render_template("changepass.html")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        stock = lookup(request.form.get('symbol'))
        if not stock:
            return apology("Please enter valid symbol", 400)

        rows = db.execute("SELECT cash FROM users WHERE id = :userid ", userid=session["user_id"])
        cash = rows[0]["cash"]
        shares = request.form.get("shares")
        try:
            shares = int(shares)
            if shares < 0:
                return apology("share must be a positive integer", 400)
        except:
            return apology("share must be a positive integer", 400)

        cost = stock["price"] * shares
        if not cost < cash:
            return apology("Not Enough cash", 400)

        db.execute("UPDATE users SET cash = :rem_cash WHERE id =:userid", rem_cash=cash - cost, userid=session["user_id"])
        db.execute("""INSERT INTO transactions (user_id, symbol, shares, price)
        VALUES(:user_id, :symbol, :shares, :price)""", user_id=session["user_id"],
                   symbol=stock["symbol"], shares=shares, price=stock["price"])
        flash("Bought!")
        return redirect("/")

    if request.method == "GET":
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    total_stocks = db.execute("""SELECT* FROM transactions WHERE user_id = ?""", session["user_id"])
    return render_template("history.html", total_stocks=total_stocks)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    if request.method == "POST":
        stock = lookup(request.form.get('symbol'))
        if not stock:
            return apology("Symbol does not exist", 400)
        return render_template("quoted.html", new_stock={'name': stock['name'],
                                                         'symbol': stock['symbol'], 'price': (stock['price'])})

    if request.method == "GET":
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():

    if request.method == "POST":

        # Ensure username was submitted
        USERNAME = request.form.get("username")
        if not USERNAME:
            return apology("must provide username", 400)

        # Ensure password was submitted
        PASS = request.form.get("password")
        if not PASS:
            return apology("must provide password", 400)

        # Ensure confirmation password was submitted
        CON_PASS = request.form.get("confirmation")
        if not CON_PASS:
            return apology("must provide confirmation password", 400)

        if not PASS == CON_PASS:
            return apology("Password must match", 400)

        try:
            session["user_id"] = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                                            username=USERNAME, hash=generate_password_hash(PASS))
        except:
            return apology("Username already existed.Try Another.", 400)

        return redirect("/login")

    if request.method == "GET":
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        stock = lookup(request.form.get('symbol'))
        if not stock:
            return apology("Please enter valid symbol", 400)
        shares = int(request.form.get("shares"))
        symbol = request.form.get("symbol")
        stocks = db.execute("""SELECT SUM(shares) as totalshares, symbol FROM transactions WHERE
        user_id = ? GROUP BY symbol HAVING totalshares > 0""", session["user_id"])

        for item in stocks:
            if item["symbol"] == symbol:
                if shares > item["totalshares"]:
                    return apology("Shares limit exeeced")

        rows = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = rows[0]["cash"]

        cost = stock["price"] * shares
        cost = cash + cost
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cost, session["user_id"])
        db.execute("""INSERT INTO transactions (user_id, symbol, shares, price)
        VALUES(:user_id, :symbol, :shares, :price)""", user_id=session["user_id"],
                   symbol=stock["symbol"], shares=-shares, price=stock["price"])
        flash("Sold!")
        return redirect("/")

    if request.method == "GET":
        symbols = db.execute("""SELECT symbol FROM transactions WHERE user_id=:id
        GROUP BY symbol having SUM(shares) > 0""", id=session["user_id"])
        return render_template("sell.html", symbols=symbols)


def errorhandler(e):
    """Handle error"""
    if not isinstance(e, HTTPException):
        e = InternalServerError()
    return apology(e.name, e.code)


# Listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)
