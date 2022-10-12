# TODO

from cs50 import get_string

# Prompt user for text input
text = get_string("Text: ")

# Declare variables to be used
letters = 0
# Words is set to 1 to account for last word in text that wont be counted while program counts spaces
words = 1
sentences = 0

# Count the number of letter, words, and sentences of text
for i in text:
    # Counts alphabetic characters in text
    if i.isalpha():
        # Adds 1 to overall count for each
        letters += 1
    # Counts spaces in text to simulate counting each word in text
    elif i == " ":
        # Adds 1 to overall count for words
        words += 1
    # Counts punctuation in text to count number of sentences
    elif i == "." or i == "!" or i == "?":
        # Adds 1 to overall count for sentences
        sentences += 1

# Coleman-Liau Index
index = 0.0588 * (letters/words*100) - 0.296 * (sentences/words*100) - 15.8

# Print grade index of text
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", round(index))