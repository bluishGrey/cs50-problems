#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int spaces = 0;
    int sents = 0;
    int texts = 0;

    string text = get_string("text? ");

    for(int i = 0, n = strlen(text); i < n; i++)
    {
        if(isspace(text[i]))
        {
            spaces++;
        }
        if(text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sents++;
        }
        if(isalpha((unsigned char)text[i]))
        {
            texts++;
        }
    }
    int words = spaces + 1;

    float L = (float) texts / words * 100;
    float S = (float) sents / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if(index < 0)
    { printf("Before Grade 1\n"); }
    else if(index > 16)
    { printf("Grade 16+\n"); }
    else
    { printf("Grade %d\n", (int) round(index)); }
}
