import csv
import re

# For counting mentions of The Office
counter =0

# Open CSV file
with open("favorites.csv", "r") as file:

    # Create DictReader
    reader = csv.DictReader(file)

    # Iterate over CSV file, counting mentions of OFFICE and THE OFFICE
    for row in reader:
        title = row["title"].strip().upper()
        if re.search("^(OFFICE|THE OFFICE)$", title):
            counter += 1

# Prints popularity
print(f"Number of people who like The Office: {counter}")