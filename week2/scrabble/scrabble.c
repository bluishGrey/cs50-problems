#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int scoresum(int);

int main(void)
{
    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    int sum1 = 0;
    int sum2 = 0;

    for (int i = 0; i < strlen(p1); i++)
    {
        int a = toupper(p1[i]);

        sum1 += scoresum(a);
    }

    for (int i = 0; i < strlen(p2); i++)
    {
        int a = toupper(p2[i]);

        sum2 += scoresum(a);
    }

    if (sum1 > sum2)
    {
        printf("Player 1 wins!\n");
    }
    else if (sum1 < sum2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int scoresum(int x)
{
    int sum = 0;
    if (x == 65 || x == 69 || x == 73 || x == 76 || x == 78 || x == 79 || x == 82 || x == 83 ||
        x == 84 || x == 85)
    {
        sum += 1;
    }
    else if (x == 68 || x == 71)
    {
        sum += 2;
    }
    else if (x == 66 || x == 67 || x == 77 || x == 80)
    {
        sum += 3;
    }
    else if (x == 70 || x == 72 || x == 86 || x == 87 || x == 89)
    {
        sum += 4;
    }
    else if (x == 75)
    {
        sum += 5;
    }
    else if (x == 74 || x == 88)
    {
        sum += 8;
    }
    else if (x == 81 || x == 90)
    {
        sum += 10;
    }
    return sum;
}
