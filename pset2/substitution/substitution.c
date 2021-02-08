/**
 * CS50x 2021
 * Problem Set 2: substitution.c
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
    bool is_valid_key(char key[]);
    void cipher(char plaintext[], char ciphertext[], char key[]);

    // Argument counts validation.
    if (argc != 2) {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Key validation.
    const string key = argv[1];

    if (! (strlen(key) == 26 && is_valid_key(key))) {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Prompt user for plaintext string.
    string plaintext = get_string("plaintext:  ");

    char ciphertext[strlen(plaintext)];

    cipher(plaintext, ciphertext, key);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}


void cipher(char plaintext[], char ciphertext[], char key[])
{
    int i = 0;

    while (plaintext[i]) {
        if (isupper(plaintext[i]))
            ciphertext[i] = toupper(key[plaintext[i] - 'A']);
        else if (islower(plaintext[i]))
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        else
            ciphertext[i] = plaintext[i];

        i++;
    }

    ciphertext[i] = '\0';
}


bool is_valid_key(char key[])
{
    for (int i = 0; key[i]; i++) {
        // Check key is all alphabetic character.
        if (! isalpha(key[i]))
            return false;

        // Check key don't contain duplicated character.
        for (int j = i + 1; key[j]; j++)
            if (key[i] == key[j])
                return false;
    }

    return true;
}