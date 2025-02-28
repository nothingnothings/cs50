import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        name = request.form.get("name")
        date = request.form.get("date")
        
        # date will be in a format like "2020-12-31"
        date = date.split("-")
        
        day = date[2]
        month = date[1]
        year = date[0]
        
        date = int(year + month + day)
        
        db.execute("INSERT INTO birthdays (name, date) VALUES (?, ?)", name, date)
        db.commit()
        return redirect("/")

    else:

        # TODO: Display the entries in the database on index.html
        entries = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", entries=entries)


