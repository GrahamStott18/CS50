# TODO

from cs50 import get_int

# Initiates program
while True:
    # Prompts user to input card number
    card = get_int("Card: ")
    # Verifys number entered
    if card > 0:
        # Program proceeds if number entered.
        break



# Determine if the card number is valid, using Luhn's algorithm
# Create luhn_checksum variable
def luhn_checksum(card):
    # Iterates through the numbers
    def digits_of(n):
        # Returns digits as a string of numbers
        return [int(d) for d in str(n)]
    digits = digits_of(card)
    # Uses negative indexing to get list of odd digits
    odd_digits = digits[-1::-2]
    # Uses negative indexing to get list of even digits
    even_digits = digits[-2::-2]
    # Sets checksum equal to zero to begin computation
    checksum = 0
    # Adds all odd digit values
    checksum += sum(odd_digits)
    # Operation to multiply even digits by 2
    for d in even_digits:
        checksum += sum(digits_of(d*2))
    # Returns checksum module 10, to obtain last digit
    return checksum % 10



# Identify the type of credit card used
lenght = 0
visa = card
master = card
amex = card

# Differentiate between VISA, Master, AMEX
lenght = len(str(card))

# Identify if card is VISA
while visa >= 10:
    visa = int(visa/10)

# Identify if card is AMEX
while amex >= 10**13:
    amex = int(amex/10**13)

# Identify if card is Mastercard
while master >= 10**14:
    master = int(master/10**14)

# Print outcome of card type
if luhn_checksum(card) == 0:
    if visa == 4 and (lenght == 13 or lenght == 16):
        print("VISA")
    elif lenght == 15 and (amex == 34 or amex == 37):
        print("AMEX")
    elif lenght == 16 and (51 <= master <= 55):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")