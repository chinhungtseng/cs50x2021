/*CS50x 2021
  Problem Set 1: mario less*/

#include <stdio.h>


int main(void)
{
    int height;
    int get_height();
    void right_aligned_pyramid(int n);

    // prompt user for height
    // if height less than 1 or greater than 8.
    do {

        height = get_height();

    } while (height < 1 || height > 8);

    // print hash-pyramid.
    right_aligned_pyramid(height);

    return 0;
}


int get_height()
{
    int number;

    printf("Height: ");
    scanf("%i", &number);

    return number;
}


void right_aligned_pyramid(int n)
{
    for (int i = 0; i < n; i++) {
        // print spaces.
        for (int s = n-1; s > i; s--) {
            printf(" ");
        }

        // Print hashes.
        for (int h = 0; h <= i; h++) {
            printf("#");
        }

        // Print line break.
        printf("\n");
    }
}
