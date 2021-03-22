import os

from utils import month_day_valid
from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # Add the user's entry into the database
        if not (name := request.form.get("name")):
            return render_template("error.html", message="Missing name")

        if not (month := request.form.get("month")):
            return render_template("error.html", message="Missing month")

        if not (day := request.form.get("day")):
            return render_template("error.html", message="Missing day")

        if not month_day_valid(month, day):
            return render_template("error.html", message="Invalid month or day, please check again")

        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)",
                   name, month, day)

        return redirect("/")

    else:

        # Display the entries in the database on index.html
        peoples = db.execute("SELECT * FROM birthdays;")

        return render_template("index.html", peoples=peoples)


