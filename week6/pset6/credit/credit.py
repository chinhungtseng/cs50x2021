import re
from cs50 import get_int, get_string


# Credit card rules.
# |------------|--------|------------|
# | TYPE       | DIGITS | START WITH |
# |------------|--------|------------|
# | AMEX       | 15     | 34, 37     |
# | MASTERCARD | 16     | 51-55      |
# | VISA       | 13, 16 | 4          |
# |------------|--------|------------|
#
credit_cards = {
    'AMEX': {
        'DIGITS': [15],
        'START_WITH': [34, 37],
    },
    'MASTERCARD': {
        'DIGITS': [16],
        'START_WITH': [51, 52, 53, 54, 55],
    },
    'VISA': {
        'DIGITS': [13, 16],
        'START_WITH': [4],
    },
}


def luhns_algorithm(card_number):
    """"Return True if card_number pass luhn's algorithm,
    otherwise False."""
    sum = 0
    for i, v in enumerate(card_number[::-1]):
        digit = int(v) * (2 if i % 2 != 0 else 1)
        digit = digit // 10 + digit % 10 if digit >= 10 else digit
        sum += digit
    return True if sum % 10 == 0 else False


def start_with(string, aList):
    """Check whether input string is with the number in aList
    Example:
        string = '19920808'
        aList = [15, 16, 17, 18, 19]
        start_with(string, aList) will return True.
    """
    pattern = "^" + "|".join([str(n) for n in aList])
    return bool(re.match(pattern, string))


def credit_card_validation(card_number):
    pass_luhn = luhns_algorithm(card_number)
    card_num_len = len(card_number)

    if pass_luhn:
        for card in credit_cards:
            card_len_pool = credit_cards[card]['DIGITS']
            is_start_with = start_with(
                card_number, credit_cards[card]['START_WITH'])

            if (card_num_len in card_len_pool) and is_start_with:
                return card

    return 'INVALID'


def main():
    card_number = get_string("Number: ")
    validation = credit_card_validation(card_number)
    print(validation)


if __name__ == "__main__":
    main()