#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("How tall is the pyramid? ");
    }
    while (h < 1 || h > 8);

    for (int i = 1; i <= h; i++)
    {
        for (int x = 0; h - i > x; x++)
        {
            printf(" ");
        }
        for (int z = 0; z < i; z++)
        {
            printf("#");
        }
        printf("\n");
    }
}
