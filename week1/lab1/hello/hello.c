/* CS50x 2021
   Lab 1: hello.c

   Prompt a message for user' name, and greeting message with user's name.
*/
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name?\n");
    printf("hello, %s\n", name);
}