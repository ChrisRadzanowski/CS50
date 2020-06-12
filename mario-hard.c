#include <stdio.h>
#include <cs50.h>


int main(void)
{
    int height;
    // Pyramid height inquiery.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    // Buliding blocks for the Mario pyramid.
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < height ; column++)
        {
            if (row + column < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        {
        printf("  ");
        }
        for (int column = 0; column <= row; column++)
        {
            printf("#");
        }
    printf("\n");
    }
}