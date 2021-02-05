/*CS50x 2021
  Lab1: population.c*/

#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int start_size, end_size, years;
    int cal_population_year(int a, int b);

    // Prompt for start size
    do {
        start_size = get_int("Start size: ");
    } while (start_size < 9);

    // Prompt for end size
    do {
        end_size = get_int("End size: ");
    } while (end_size < start_size);

    // Calculate number of years until we reach threshold
    years = cal_population_year(start_size, end_size);

    // Print number of years
    printf("Years: %i\n", years);

    return 0;
}

int cal_population_year(int a, int b)
{
    int years = 0;

    while (a < b) {
        a = a + (a / 3) - (a / 4);
        years++;
    }

    return years;
}
