# CS50 Final Project
## Video Demo:  <https://youtu.be/zURMWJ73_zE>
For a brief demonstration video follow the link above.
## Description:
This is my final project for the Harvard CS50x course.

This project is a web application built on flask framework that allows users to send, receive, and view email messages. Users are required to register an email address and password to access webpage. Once registered/logged in users are able to view previously sent and received messages that have been stored to the database. Users can also reply to received emails and view replys.

All data is housed in the project.db file. This file stores the users account details such as emails and passwords for login. It also stores details of the email messages that are sent and received between users. The email details stored are sender, recipient, subject, body, and time stamp of each message sent on the webpage.

This project has been created using HTML, Python, and CSS.

All previous projects and assignments can be found <b>[here.](https://github.com/GrahamStott18/CS50)</b>

## Features of Application:
1. Create new email account
2. Log in to established email account
3. View previously received email repository
4. Receive email sent from another user
5. Email details include sender, recipient, subject, body of email, and timestamp
6. Compose new email message to send to user
7. View previously sent email repository
8. Respond to received email(s)
9. Log out of email account

## Files and Directories
- `application.py`
    - Python file that provides framework for my webpage.
- `project.db`
    - Database that is setup to store users login details as well as emails sent and received.
- `helpers.py` - Contains defined functions used within application.py framework.
- `README.md` - Details application details for overview.
- `requirements.txt` - All project dependencies listed within file.
- `static directory` (All static file held in this directory)
    - `styles.css`
        - Contains styles used throughout the application.
- `templates` ( All html files are held in this directory)
    - `apology.html` - Page setup for apology usage
    - `compose.html` - HTML page setup for Compose webpage link.
    - `email.html` - HTML page setup for email repository webpage link.
    - `index.html` - HTML page framework for email viewing on mainpage of application once logged in.
    - `layout.html` - HTML page setup for for application webpage framework.
    - `login.html` - HTML page setup for user login webpage link.
    - `register.html` - HTML page setup for user registration link.
    - `reply.html` - HTML page setup for webpage setup to send replys to emails.

## To run the web application use these commands:
```
$ export FLASK_APP=application.py
$ flask run
```
## Requirements:
- cs50
- Flask
- Flask-Session

## About CS50
CS50 is a openware course from Havard University and taught by David J. Malan

Introduction to the intellectual enterprises of computer science and the art of programming. This course teaches students how to think algorithmically and solve problems efficiently. Topics include abstraction, algorithms, data structures, encapsulation, resource management, security, and software engineering. Languages include C, Python, and SQL plus students’ choice of: HTML, CSS, and JavaScript (for web development).
