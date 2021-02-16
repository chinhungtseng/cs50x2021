#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);


int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    bool compare_string(const char name1[], const char name2[]);

    for (int i = 0; i < candidate_count; i++)
        if (compare_string(name, candidates[i].name)) {
            candidates[i].votes++;
            return true;
        }

    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    void sort_candidates(void);
    int winner_counts = 1;

    sort_candidates();

    for (int i = 0; i < candidate_count - 1; i++)
        if (candidates[i].votes == candidates[i + 1].votes)
            winner_counts++;

    for (int i = 0; i < winner_counts; i++)
        printf("%s\n", candidates[i].name);
}

// Check if two strings are equal or not.
bool compare_string(const char name1[], const char name2[])
{
    int i = 0;
    bool equal = false;

    while ((name1[i] == name2[i]) && name1[i] && name2[i])
        i++;

    if (name1[i] == '\0')
        equal = true;

    return equal;
}

// Sort the candidates array in desending order by .votes value. 
void sort_candidates(void)
{
    candidate temp;
    for (int i = 0; i < candidate_count - 1; i++)
        for (int j = i + 1; j < candidate_count; j++)
            if (candidates[i].votes < candidates[j].votes) {
                temp = candidates[i];
                candidates[i] = candidates[j];
                candidates[j] = temp;
            }
}
