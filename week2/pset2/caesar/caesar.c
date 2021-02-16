/**
 * CS50x 2021
 * Problem Set 2: caesar.c
 */

#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, char *argv[])
{
    int k;
    string text;
    bool is_literal_number(string text);
    void offset_string(char text[], int offset);

    // Check only contain one command line argument.
    // Check all the characters from argument is literal number.
    if (! (argc == 2 && is_literal_number(argv[1]))) {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert input string to integer.
    k = atoi(argv[1]);

    // Prompt user for plain-text.
    text = get_string("plaintext:  ");

    // Offset the text by key.
    offset_string(text, k);

    // Output the cipher-text.
    printf("ciphertext: %s\n", text);

    return 0;
}


bool is_literal_number(string text)
{
    bool valid_number = false;

    for (int i = 0; text[i]; i++) {
        // If the first character is '-', skip to next
        // element, but not set valid_number to true.
        if (i == 0 && text[i] == '-')
            continue;

        if (text[i] >= '0' && text[i] <= '9')
            valid_number = true;
        else
            return false;
    }

    return valid_number;
}


void offset_string(char text[], int offset)
{
    int i = 0;

    while (text[i]) {
        if (isupper(text[i]))
            text[i] = ((text[i] - 'A' + offset) % 26) + 'A';
        else if (islower(text[i]))
            text[i] = ((text[i] - 'a' + offset) % 26) + 'a';
        i++;
    }
}
