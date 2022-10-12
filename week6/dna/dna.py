import csv
import sys


def main():

    # TODO: Check for command-line usage

    # Checks if 3 required files were typed into command-line when program initiated
    if len(sys.argv) != 3:
        # Prints error message if arguments not equal to 3
        sys.exit("python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable

    database = []
    # Opens first argument "file" from command-line argument, as a file
    with open(sys.argv[1], 'r') as file:
        # Uses DictReader to read file
        reader = csv.DictReader(file)
        # Reads each row in file
        for row in reader:
            # Appends each row from file to database
            database.append(row)

    # TODO: Read DNA sequence file into a variable

    # Opens second argument "file" from command-line argument, as a file
    with open(sys.argv[2], 'r') as file:
        dna_sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence

    # Extracts a list of subsequences from the database, by extracting all the keys
    subsequences = list(database[0].keys())[1:]

    # Adds to the dictionary for each subsequence
    result = {}
    for subsequence in subsequences:
        result[subsequence] = longest_match(dna_sequence, subsequence)

    # TODO: Check database for matching profiles
    for person in database:
        match = 0
        for subsequence in subsequences:
            if int(person[subsequence]) == result[subsequence]:
                match += 1

        # If all subsequences match
        if match == len(subsequences):
            print(person["name"])
            return

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
