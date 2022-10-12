# TODO

# Imports get_int from cs50 library
from cs50 import get_int

while True:
    # Prompt user to input height
    n = get_int("Height: ")
    # Ensures inputted number is between 1 and 8, before continuing
    if n > 0 and n < 9:
        break

# Tells program where to put spaces and #, based on inputted height
# i is rows, j is columns
for i in range(0, n, 1):
    for j in range(0, n+i+3, 1):
        if (j == n or j == n+1 or i+j < n-1):
            print(" ", end="")
        else:
            print("#", end="")
    print()