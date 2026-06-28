#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int count;
    long num;
    do
      {
       count = 0;
       num = get_long("Number: ");
       long temp = num;
       while (temp != 0)
       {
           temp /= 10;
           count++;
       }
      }
    while(num < 1);
    if(count != 16 && count != 15 && count != 13)
    {
        printf("INVALID\n");
        return 0;
    }
    //카드번호 num 받고, 몇자릿수 count인지 판별

    long temp = num;
    int position = 1;
    int digit;
    int sum_odd = 0;
    int sum_even = 0;

    while (temp != 0)
    {
        digit = temp % 10;

        if (position % 2 == 0)
        {
            sum_even += ((digit*2)%10 + (digit*2)/10);
        }
        else
        {
            sum_odd += digit;
        }
        temp /=10;
        position++;
    }
    // + 홀짝 구분 및 총합
    // position은 몇 번째 자릿수인지, digit은 그 자리의 값이 얼마인지

    if((sum_odd + sum_even)%10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long temp2 = num;
    if (count == 13)
    {
        for(int a = 0; count-1 > a; a++)
        {
            temp2 /= 10;
        }
        if (temp2 == 4)
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    if (count == 15)
    {
        for(int a = 0; count-2 > a; a++)
        {
            temp2 /= 10;
        }
        if (temp2 == 34 || temp2 == 37)
        {
            printf("AMEX\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    if (count == 16)
    {
        for(int a = 0; count-2 > a; a++)
        {
            temp2 /= 10;
        }
        if (temp2 == 51 || temp2 == 52 || temp2 == 53 ||
            temp2 == 54 || temp2 == 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            temp2 /= 10;
            if (temp2 == 4)
            {
                printf("VISA\n");
                return 0;
            }
            else
            {
                printf("INVALID\n");
                return 0;
            }
        }
    }
}
