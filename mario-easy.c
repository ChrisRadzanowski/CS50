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
            if (row + column < height - 1)//height-1 because of int column=0, if we wouldn't subtract 1 we would have one more row than necessary
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }        
    printf("\n");
    }
}