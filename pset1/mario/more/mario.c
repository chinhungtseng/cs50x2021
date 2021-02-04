/*CS50x 2021
  Problem Set 1: mario more*/

#include <stdio.h>


int main(void)
{
    int height;
    int get_height();
    void print_pyramid(int n);

    // prompt user for height
    // if height less than 1 or greater than 8.
    do {

        height = get_height();

    } while (height < 1 || height > 8);

    // print hash-pyramid.
    print_pyramid(height);

    return 0;
}


int get_height()
{
    int number;

    printf("Height: ");
    scanf("%i", &number);

    return number;
}


void print_pyramid(int n)
{

    for (int i = 0; i < n; i++) {

        // Print left-side.
        for (int s = n-1; s > i; s--) {
            printf(" ");
        }

        for (int h = 0; h <= i; h++) {
            printf("#");
        }

        printf("  ");

        // Print right-side.
        for (int h = 0; h <= i; h++) {
            printf("#");
        }

        // Print line break.
        printf("\n");
    }
}
