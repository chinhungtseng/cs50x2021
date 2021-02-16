/**
 * CS50x 2021
 * Problem Set 1: credit.c
 */

#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>


int main(void)
{
    long card_number;
    void credit_card_validation(long card_number);

    // Prompt user for credit card number.
    card_number = get_long("Number: ");

    // Credit card number validation.
    credit_card_validation(card_number);

    return 0;
}


// Get digits of card_number.
int number_of_digits(long n)
{
    int len = 0;

    // Convert negative value to positive value.
    if (n < 0)
        n = -n;

    while (n > 0) {
        n /= 10;
        len++;
    }

    return len;
}


/**
 * Credit card number validation.
 *
 * Credit card rules.
 * |------------|--------|------------|
 * | TYPE       | DIGITS | START WITH |
 * |------------|--------|------------|
 * | AMEX       | 15     | 34, 37     |
 * | MASTERCARD | 16     | 51-55      |
 * | VISA       | 13, 16 | 4          |
 * |------------|--------|------------|
 */
void credit_card_validation(long card_number)
{
    int ndigits;
    bool isValidAlgor;
    int number_of_digits(long n);
    bool luhn_algorithm(long number);
    bool is_in(int target, int *array, int n);

    ndigits = number_of_digits(card_number);
    isValidAlgor = luhn_algorithm(card_number);

    if (ndigits == 15 && isValidAlgor) {
        int start_with[2] = {34, 37};
        int first_two_digits = (int) (card_number / (long) 1e13);

        if (is_in(first_two_digits, start_with, 2))
            printf("AMEX\n");
        else
            printf("INVALID\n");

    } else if (ndigits == 16 && isValidAlgor) {
        int start_with[5] = {51, 52, 53, 54, 55};
        int first_two_digits = (int) (card_number / (long) 1e14);

        if (is_in(first_two_digits, start_with, 5))
            printf("MASTERCARD\n");
        else if ((first_two_digits / 10) == 4)
            printf("VISA\n");
        else
            printf("INVALID\n");

    } else if (ndigits == 13 && isValidAlgor) {
        int start_with = 4;
        int first_digits = (int) (card_number / (long) 1e12);

        if (first_digits == start_with)
            printf("VISA\n");
        else
            printf("INVALID\n");

    } else
        printf("INVALID\n");
}

/**
 * Luhn’s Algorithm
 *
 *   1) Multiply every other digit by 2, starting with the number’s
 *      second-to-last digit, and then add those products’ digits together.
 *
 *   2) Add the sum to the sum of the digits that weren’t multiplied by 2.
 *
 *   3) If the total’s last digit is 0 (or, put more formally,
 *      if the total modulo 10 is congruent to 0), the number is valid!
 */
bool luhn_algorithm(long number)
{
    int digit, ndigits;
    long results = 0;
    bool isValid = true;
    int number_of_digits(long n);

    ndigits = number_of_digits(number);

    for (int i = 1; i <= ndigits; i++) {
        digit = number % 10;
        number /= 10;

        if (!(i % 2)) {
            digit *= 2;
            if (number_of_digits(digit) > 1) {
                digit = (digit % 10) + (digit / 10);
            }
        }
        results += digit;
    }

    if (results % 10)
        isValid = false;

    return isValid;
}

bool is_in(int target, int *array, int n)
{
    int *end = (array + n - 1);
    while (array <= end) {
        if ( *array == target)
            return true;
        array++;
    }
    return false;
}
