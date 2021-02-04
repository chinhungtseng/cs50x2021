/**
 * CS50x 2021
 * Problem Set 1: cash
 */

#include <stdio.h>
#include <math.h>
#include <cs50.h>


int main(void)
{
    int cents;
    int count_coins(int n);

    // Prompt user for non-negative change owed.
    do {
        cents = round(get_float("Change owed: ") * 100);
    } while (cents < 0);

    printf("%i\n", count_coins(cents));

    return 0;
}

int count_coins(int n)
{
    int base, counts = 0;
    int coin_types[4] = {25, 10, 5, 1};

    if (!n)
      return 0;

    for (int i = 0; i < 4; i++) {
        base = coin_types[i];

        while (n >= base) {
            n -= base;
            counts++;
        }
    }

    return counts;
}