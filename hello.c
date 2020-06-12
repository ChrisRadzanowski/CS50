#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // This will ask the user for his/her name
    string name = get_string("What is your name?\n");
    // The user's name will be placed in the placeholder's location
    printf("hello, %s\n", name);
}