#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cg;
    do
    {
       cg = get_int("Change? ");
    }
    while (cg < 0);


    int q = 0; int d = 0; int n = 0; int p = 0;
    while (cg >= 25)
    {
        cg = cg - 25; q++;
    }

    while (cg >= 10)
    {
        cg = cg - 10; d++;

    }
    while (cg >= 5)
    {
        cg = cg - 5; n++;
    }
    while (cg >= 1)
    {
        cg = cg - 1; p++;
    }
    printf("%i\n", q + d + n + p);

}
