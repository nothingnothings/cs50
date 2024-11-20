import os
from datetime import datetime

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response



@app.route("/")
@login_required
def index():
    """Show portfolio of stocks of given user"""

    stocks = db.execute("SELECT * FROM stocks WHERE user_id = ?", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])[0]["cash"]

 # Initial variables for total values
    # total_value = cash
    total_value = sum(stock["shares"] * stock["price"] for stock in stocks)
    grand_total = cash

    print(stocks)

    for stock in stocks:
            quote = lookup(stock["symbol"])
            stock["name"] = quote["name"]
            stock["price"] = quote["price"]
            stock["value"] = stock["price"] * stock["shares"]
            # total_value += stock["value"]
            grand_total += stock["value"]

    print(stocks)


    return render_template("index.html", entries=stocks, cash=cash, total_value=total_value, grand_total=grand_total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        shares = request.form.get("shares")

        # Check for missing symbol or shares
        if not symbol:
            return apology("Must provide a symbol", 400)
        if not shares:
            return apology("Must provide number of shares", 400)

        # Lookup the symbol
        stock = lookup(symbol)
        if not stock:
            return apology("Invalid symbol", 400)

        # Validate shares
        try:
            shares = int(shares)
            if shares <= 0:
                return apology("Shares must be a positive integer", 400)
        except ValueError:
            return apology("Shares must be a positive integer", 400)

        # Calculate cost
        cost = stock["price"] * shares


        # Check if user can afford the shares
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        if cost > user_cash:
            return apology("Can't afford", 400)

        updated_cash = user_cash - cost


        # Add stock into the stocks table
        db.execute("INSERT INTO stocks (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", session["user_id"], symbol, shares, stock["price"])
        # Perform transaction
        db.execute("INSERT INTO transactions (user_id, transaction_type, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, ?)", user_id, "BUY", stock["symbol"], shares, stock["price"], datetime.now())
        # Update cash
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", cost, user_id)

        # Flash message to user:
        flash(f"Bought {shares} of {symbol} for {usd(cost)}, Updated cash: {usd(updated_cash)}")

        # Redirect to homepage
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
        entries = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])
        for entry in entries:
            entry["price"] = usd(entry["price"])
            if entry["transaction_type"] == "BUY":
                entry["transaction_type"] = ""
            else:
                entry["transaction_type"] = "-"
        return render_template("history.html", entries=entries)



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

        return login_user(request.form.get("username"), request.form.get("password"))

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")




def login_user(name, hashed_password):
    """Log user in"""
   # Query database for username
    rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
    if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
        return apology("invalid username and/or password", 403)

    # Remember which user has logged in
    session["user_id"] = rows[0]["id"]

    # Redirect user to home page
    return redirect("/")





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
    """Get stock quote."""
# User reached route via GET (as by clicking a link or via redirect)
    if request.method == "GET":
        return render_template("quote.html")

    # User reached route via POST (as by submitting a form via POST)
    else:
        symbol = request.form.get("symbol")

        if not symbol :
            return apology("Please enter a symbol")

        # Lookup a stock symbol and return a stock price as a dictionary
        stock = lookup(symbol.upper())

        if stock == None or not stock:
            return apology("invalid symbol")

        print(float(stock['price']))

        # If lookup is succesful, display the stock price
        # if stock:
        return render_template("quoted.html", name = stock['name'], price = usd(float(stock['price'])), symbol = stock['symbol'])



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        # Check if any fields are empty
        if not request.form.get("username") or not request.form.get("password") or not request.form.get("confirmation"):
            return apology("Please fill in all fields", 400)  # Explicitly set status code 400

        # Check if passwords match
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("Passwords do not match", 400)  # Explicitly set status code 400

        # Process the valid form
        name = request.form.get("username")
        password = request.form.get("password")
        hashed_password = generate_password_hash(password)

        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", name, hashed_password)
            login_user(name, hashed_password)
        except Exception:
            return apology("Username already exists", 400)  # Explicitly set status code 400

        return redirect("/login")
    else:
        return render_template("register.html")



@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if symbol == "" or shares == "":
            return apology("Please fill in all fields")

        shares = int(shares)

        if shares < 0:
            return apology("Shares must be positive")

        # Check if the user has enough shares
        rows = db.execute("SELECT * FROM stocks WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)
        
        # Check user cash:
        cash = db.execute("SELECT cash FROM users WHERE user_id = ?", session["user_id"])

        if len(rows) == 0:
            return apology("You do not own enough shares of this stock")

        elif len(rows) > 0 and rows[0]["shares"] < shares:
            return apology("You do not own enough shares of this stock")


        # Calculate the total cost of the shares
        price = lookup(symbol)["price"]
        total = float(shares) * price
        
        updated_cash = float(cash[0]["cash"]) - total
        

        # If the user sells all of their shares, delete the entry from the database
        if shares == rows[0]["shares"]:
            db.execute("DELETE FROM stocks WHERE user_id = ? AND symbol = ?", session["user_id"], symbol)

        # Otherwise, update the entry in the database
        else:
            db.execute("UPDATE stocks SET shares = shares - ? WHERE user_id = ? AND symbol = ?", shares, session["user_id"], symbol)

        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total, session["user_id"])

        db.execute("INSERT INTO transactions (user_id, transaction_type, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?, ?)", session["user_id"], "SELL", symbol, shares, price, datetime.now())

       # Flash message to user:
        flash(f"Sold {shares} of {symbol} for {usd(price)}, Updated cash: {usd(updated_cash)}")

        return redirect("/")
    else:
        user_shares = db.execute("SELECT * FROM stocks WHERE user_id = ?", session["user_id"])
        
        for row in user_shares:
            row["price"] = usd(row["price"])
            row["shares"] = int(row["shares"])
        return render_template("sell.html", entries=user_shares)
