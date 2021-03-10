import sys
import csv


# Command line arguments
args = sys.argv

# STR sequences header
STRS_H = []


def load_database():
    database = []

    with open(args[1], "r") as f:
        reader = csv.DictReader(f)

        # Update STR sequences header, the first
        # element is name, so we drop it out.
        global STRS_H
        STRS_H = reader.fieldnames[1:]

        for row in reader:
            for k in STRS_H:
                row[k] = int(row[k])
            database.append(row)

    return database


def load_sequence_data():
    with open(args[2], "r") as f:
        sequence = f.readline()

    return sequence


def str_sequence_counter(sequence):
    # Initialize counter all values to zero.
    counter = {k: 0 for k in STRS_H}

    for k in counter:
        n = find_maxnum_key(k, sequence)
        counter[k] = n

    return counter


def find_maxnum_key(key, text):
    count = 0
    pattern = key
    while pattern in text:
        count += 1
        pattern += key

    return count


def search_database(target, database):
    for people in database:
        if all([people[k] == target[k] for k in STRS_H]):
            return people["name"]

    return "No match"


def main():
    # Check for correct number of args.
    if len(args) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read databases data.
    database = load_database()

    # Read sequences data.
    sequence = load_sequence_data()

    # Count the number of each STR sequence.
    target = str_sequence_counter(sequence)

    # Search target in database, if match, return target's name;
    # otherwise return "No match".
    result = search_database(target, database)

    print(result)


if __name__ == "__main__":
    main()
