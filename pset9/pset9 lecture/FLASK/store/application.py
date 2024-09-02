from flask import Flask ,render_template ,request , redirect
from flask_mail import Mail, Message

app = Flask(__name__)
app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 587
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True
APP.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
mail = Mail(app)

SPORTS = [
     "Dodgeball",
     "Flag Football",
     "Soccer",
     "Volleyball",
     "Ultimate Frisbee"
]


@app.route("/")
def index():
   return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name and not  sport:
        return render_template("error.html", message="Missing name and sport")
    elif not name:
        return render_template("error.html", message="Missing name")
    elif not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid sport")

    message = Message("You are registered!", recipients=[email])
    mail.send(message)

    return render_template("success.html")
