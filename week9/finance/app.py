import os
import sys

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, jsonify
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from datetime import datetime

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


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
    """Show portfolio of stocks"""

    # Create a table for index
    rows = db.execute(
        "SELECT symbol, SUM(shares) FROM transactions WHERE user_id=:user_id GROUP BY symbol HAVING SUM(shares) > 0", user_id=session["user_id"])

    # Creates a place to save the informations
    holdings = []
    all_total = 0

    for row in rows:
        stock = lookup(row['symbol'])
        sum_value = (stock["price"] * row["SUM(shares)"])
        holdings.append({"symbol": stock["symbol"], "name": stock["name"], "shares": row["SUM(shares)"], "price": usd(
            stock["price"]), "total": usd(sum_value)})
        all_total += stock["price"] * row["SUM(shares)"]

    rows = db.execute("SELECT cash FROM users WHERE id=:user_id",
                      user_id=session["user_id"])
    cash = rows[0]["cash"]
    all_total += cash

    return render_template("index.html", holdings=holdings, cash=usd(cash), all_total=usd(all_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    # Display form to buy stock
    if request.method == "GET":
        return render_template("buy.html")

    else:
        symbol = request.form.get("symbol")
        shares = request.form.get("shares", type=int)

        if not symbol:
            # Returns error message if users inputs no symbol.
            return apology("Must Provide Valid Symbol")

        stock = lookup(symbol.upper())

        if stock == None:
            # Returns error message if users inputs invalid symbol.
            return apology("Symbol Does Not Exist")

        if not shares:
            return apology("Must Provide Number Of Shares")

        if shares < 1:
            return apology("Share Not Allowed")

        transaction_value = shares * stock["price"]

        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        if user_cash < transaction_value:
            return apology("Not Enough Available Money")

        updt_cash = user_cash - transaction_value

        # UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        now = datetime.now()
        date = now.strftime("%Y-%m-%d %H:%M:%S")

        # INSERT INTO table_name (column1, comlumn2, column3, ...) VALUES (value1, value2, value3, ...)
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)", user_id, stock["symbol"],
                    shares, stock["price"], date)

        flash("Bought!")

        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    user_id = session["user_id"]
    transactions_db = db.execute("SELECT * FROM transactions WHERE user_id = :id", id=user_id, )
    return render_template("history.html", transactions=transactions_db)



@app.route("/add_cash", methods=["GET", "POST"])
@login_required
def add_cash():
    """User can add cash to account"""

    if request.method == "GET":
        return render_template("add.html")
    else:
        new_cash = int(request.form.get("new_cash"))

        if not new_cash:
            return apology("You Must Use Money")

        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        updt_cash = user_cash + new_cash

        # UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        return redirect("/")


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
    """Get stock quote."""

    # Connects quote.html to the webpage
    if request.method == "GET":
        return render_template("quote.html")

    else:
        # Connects to field to input symbol.
        symbol = request.form.get("symbol")

        if not symbol:
            # Returns error message if users inputs invalid symbol.
            return apology("Must Give Symbol")

        stock = lookup(symbol.upper())

        if stock == None:
            return apology("Symbol Does Not Exist")

        return render_template("quoted.html", name=stock["name"], price=stock["price"], symbol=stock["symbol"])



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Connects register.html to the Register button on webpage.
    if request.method == "GET":
        return render_template("register.html")

    else:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username:
            # Returns error message if Username not correct
            return apology("Must Give Username")

        if not password:
            # Returns error message if Password not correct
            return apology("Must Give Password")

        if not confirmation:
            # Returns error message if Confirmation not correct
            return apology("Must Give Confirmation")

        if password != confirmation:
            # Returns error message if Passwords do not match
            return apology("Passwords Do Not Match")

        # Creates variable for imported function to pass on the password.
        hash = generate_password_hash(password)

        try:
            # INSERT INTO table_name (column1, comlumn2, column3, ...) VALUES (value1, value2, value3, ...)
            new_user = db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
        except:
            return apology("Username Already Exists")

        session["user_id"] = new_user

        # Returns to main page.
        return redirect("/")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    if request.method == "GET":
        user_id = session["user_id"]
        symbols_user = db.execute(
            "SELECT symbol FROM transactions WHERE user_id = :id GROUP BY symbol HAVING SUM(shares) > 0", id=user_id)
        # Creates for loop
        return render_template("sell.html", symbols=[row["symbol"] for row in symbols_user])

    else:
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        if not symbol:
            # Returns error message if users inputs no symbol.
            return apology("Must Provide Valid Symbol")

        stock = lookup(symbol.upper())

        if stock == None:
            # Returns error message if users inputs invalid symbol.
            return apology("Symbol Does Not Exist")

        if shares < 0:
            return apology("Share Not Allowed")

        transaction_value = shares * stock["price"]

        user_id = session["user_id"]
        user_cash_db = db.execute("SELECT cash FROM users WHERE id = :id", id=user_id)
        user_cash = user_cash_db[0]["cash"]

        user_shares = db.execute(
            "SELECT SUM(shares) AS shares FROM transactions WHERE user_id = :id AND symbol = :symbol GROUP BY symbol", id=user_id, symbol=symbol)
        user_shares_real = user_shares[0]["shares"]

        if shares > user_shares_real:
            return apology("You Do Not Have Enough Shares")

        updt_cash = user_cash + transaction_value

        # UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition
        db.execute("UPDATE users SET cash = ? WHERE id = ?", updt_cash, user_id)

        now = datetime.now()
        date = now.strftime('%Y-%m-%d %H:%M:%S')

        # INSERT INTO table_name (column1, comlumn2, column3, ...) VALUES (value1, value2, value3, ...)
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price, date) VALUES (?, ?, ?, ?, ?)",
                    user_id, stock["symbol"], (-1)*shares, stock["price"], date)

        flash("Sold!")

        return redirect("/")

