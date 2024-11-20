import csv
import sys


def main():

    # Initialize variables
    database = []
    dna = ""
    str_list = []

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py large.csv 1.txt")
        sys.exit(1)

    # Read database file into a variable
    with open(sys.argv[1], "r") as database_file:
        reader = csv.DictReader(database_file)  # Use DictReader for easier access
        str_list = reader.fieldnames[1:]  # Extract STRs (skip "name" column)
        for row in reader:
            # Convert STR counts to integers for comparison
            for str_ in str_list:
                row[str_] = int(row[str_])
            database.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as dna_file:
        dna = dna_file.read()

    # Find longest match of each STR in DNA sequence
    str_counts = {}
    for str_ in str_list:
        str_counts[str_] = longest_match(dna, str_)

    # Check database for matching profiles
    for row in database:
        if all(row[str_] == str_counts[str_] for str_ in str_list):
            print(row["name"])
            return

    # If no match found
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

    # After checking for runs at each character in sequence, return longest run found
    return longest_run


main()
