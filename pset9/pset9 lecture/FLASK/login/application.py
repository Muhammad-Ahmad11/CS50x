from flask import Flask, redirect, render_template, session, request
from flask_session import Session

app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/")
def index():
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")


@app.route("/login",methods=["GET","POST"])
def login():
    if request.method == "POST":
        # Remember that user logged in
        session["name"]= request.form.get("name")
        # Redirect user to /
        return redirect("/")
    return render_template("login.html")

@app.route("/logout")
def logout():
       session["name"] = None
       return redirect("/")

