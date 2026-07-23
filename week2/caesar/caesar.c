#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // 1. argc가 2가 아니면 -> Usage 출력, return 1
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // 2. argv[1]의 모든 글자가 숫자가 아니면 -> Usage 출력, return 1
    // isdigit은 글자 하나를 받는 함수
    for (int i = 0, l = strlen(argv[1]); i < l; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // 3. key 구하기 (atoi 이용해 string을 int로 변환)
    int key = atoi(argv[1]);

    // 4. plaintext 입력받기 (get_string)
    string plaintext = get_string("plaintext:  ");

    // 5. plaintext 길이만큼 ciphertext 배열 준비
    int n = strlen(plaintext);
    char ciphertext[n + 1];

    // 6. 한 글자씩 순회하면서 :
    //    - 대문자면 'A' 기준으로 회전
    //    - 소문자면 'a' 기준으로 회전
    //    - 둘 다 아니면 그대로 복사

    for (int i = 0; i < n; i++)
    {
        char new_char;

        if (isupper(plaintext[i]))
        {
            int offset = plaintext[i] - 'A';
            int rotated = (key + offset) % 26;
            new_char = 'A' + rotated;
        }
        else if (islower(plaintext[i]))
        {
            int offset = plaintext[i] - 'a';
            int rotated = (key + offset) % 26;
            new_char = 'a' + rotated;
        }
        else
        {
            new_char = plaintext[i];
        }
        ciphertext[i] = new_char;
    }
    ciphertext[n] = '\0';

    printf("plaintext: %s\n", plaintext);
    printf("ciphertext: %s\n", ciphertext);
}
