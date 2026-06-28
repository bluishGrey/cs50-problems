#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("How tall is the Pyd? ");
    }
    while (h > 8 || h < 1);

    for (int i = 1; i <= h; i++)
    {
        for (int z = 0; h - i > z; z++)
        {
            printf(" ");
        }
        for (int x = 0; i > x; x++)
        {
            printf("#");
        }
        printf("  ");
        for (int c = 0; i > c; c++)
        {
            printf("#");
        }
        printf("\n");
    }
}
