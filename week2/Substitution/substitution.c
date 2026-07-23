// CLI 한 번으로 Key 얻기, 대소문자에 영향 안가게
// CLI 한 번 아니면 에러 메세지와 함께 프로그램 종료 //done
// Key 조건 : 26자리, 알파벳만, 각 알파벳 한 번 씩만, 아니면 에러메세지, 프로그램 종료 //done
// get_string 이용해 plaintext:  통해 plaintext 얻기 //done
// ciphertext:  이후에 치환된 텍스트 출력
// 대소문자 유지해야함!
// ciphertext 출력 후 0 출력해 종료

#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: substitution key");
        return 1;
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Usage: substitution key");
        return 1;
    }


    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: substitution key");
            return 1;
        }
    }

    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int s = 0; s < n; s++)
        {
            if (i != s)
            {
              if  (toupper(argv[1][i]) == toupper(argv[1][s]))
              {
                  printf("Usage: substitution key");
                  return 1;
              }
            }

        }
    }



    string plaintext = get_string("plaintext:  ");
    int m = strlen(plaintext);
    char ciphertext[m+1];

    for (int i = 0; i < m; i++)
    {
        char new_char;
        if (isupper(plaintext[i]))
        {
            int offset = plaintext[i] - 'A';
            new_char = argv[1][offset];
            ciphertext[i] = toupper(new_char);
        }
        else if (islower(plaintext[i]))
        {
            int offset = plaintext[i] - 'a';
            new_char = argv[1][offset];
            ciphertext[i] = tolower(new_char);
        }
        else
        {
            new_char = plaintext[i];
            ciphertext[i] = new_char;
        }


    }

    ciphertext[m] = '\0';

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
