/*CS50x 2021
  Lab 2: scrabble.c */

#include <cs50.h>
#include <stdio.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);


int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
        printf("Player 1 wins!\n");
    else if (score1 < score2)
        printf("Player 2 wins!\n");
    else
        printf("Tie!\n");
}


// Compute and return score for string
int compute_score(string word)
{
    int i = 0, score = 0, atype;
    int alphabetic(char c);

    while (word[i]) {
        atype = alphabetic(word[i]);

        if (atype == 0)
            score += POINTS[word[i] - 97];  // lower case.
        else if (atype == 1)
            score += POINTS[word[i] - 65];  // upper case.

        i++;
    }

    return score;
}


/**
 * Check if input character is alphabetic.
 *
 * if c is alphabetic and lower case, return 0,
 * if c is alphabetic and upper case, return 1,
 * if not alphabetic, return -1.
 */
int alphabetic(char c)
{
    if (c >= 'a' && c <= 'z')
        return 0;
    else if (c >= 'A' && c <= 'Z')
        return 1;
    return -1;
}