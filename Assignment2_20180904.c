/*
Assignment #2. 덧셈 암호, 곱셈 암호, 아핀 암호 구현하기
- 소스 코드 내 주요 기능에 대해 주석으로 설명 첨부
- 보고서에는 구현한 결과물의 동작화면과 실제 데이터를 이용한 테스트 결과를 캡처하여 첨부하고,
어떻게 구현하였는지 구체적으로 설명할 것.
- 만약 기한 내에 구현을 못했으면, 구현을 진행한 부분까지 제출하고
어떤 부분에서 구현이 어려웠는지 분석해서 보고서에 작성할 것.
*/

#include <stdio.h>
#include <stdlib.h>

// A : 65, a : 97 -> 97 + 0 = a
// plain, cipher가 소문자 알파벳으로만 이루어져 있다고 가정(Zn=26)
#define NUMBER_OF_ALPHABET 26
#define ASCII_BASE 97

// 확장 유클리드 알고리즘 계산 함수
void ex_gcd(int key, int *s, int *t)
{
    int r1 = NUMBER_OF_ALPHABET;
    int r2 = key;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int q, r;           // 몫, 나머지
    int s_temp, t_temp; // s와 t의 중간 연산 저장용

    while (r2 != 0)
    {
        q = r1 / r2;
        r = r1 % r2;
        s_temp = s1 - q * s2;
        t_temp = t1 - q * t2;

        r1 = r2;
        r2 = r;

        s1 = s2;
        s2 = s_temp;

        t1 = t2;
        t2 = t_temp;
    }
    // s와 t값을 포인터로 리턴
    *s = s1;
    *t = t1;
    return;
}

// 덧셈에 대한 역원 산출 함수
int find_add_inverse(int key)
{
    if (key > NUMBER_OF_ALPHABET || key <= 0) // 키값 범위 체크
        return -1;
    return (NUMBER_OF_ALPHABET - key);
}

// 곱셈에 대한 역원 산출 함수
int find_mul_inverse(int key)
{
    int s, t = 0;
    ex_gcd(key, &s, &t);

    // 필요충분조건 체크
    if ((s * NUMBER_OF_ALPHABET + t * key) != 1)
    {
        printf("can't find mul inverse!\n");
        return -1;
    }

    if (t < 0)
        // 피제수인 t가 음수인 경우 나머지인 r이 음수가 되므로 이를 양수로 바꾸어준다.
        return (t % NUMBER_OF_ALPHABET + NUMBER_OF_ALPHABET);
    else
        // t를 Zn에 대응시킨다.
        return t % NUMBER_OF_ALPHABET;
}

// 덧셈 암호
void encrypt_add(char *str, int key)
{
    if (find_add_inverse(key) == -1) // 키값 범위 체크
    {
        printf("out of range!\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - ASCII_BASE;
        str[i] = (str[i] + key) % NUMBER_OF_ALPHABET;
        str[i] = str[i] + ASCII_BASE;
    }
    return;
}

void decrypt_add(char *str, int key)
{
    // 역원 찾기
    int inverse = find_add_inverse(key);
    if (inverse == -1)
    {
        printf("out of range!\n");
        return;
    }
    
    //복호화
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - ASCII_BASE;
        str[i] = str[i] - key;
        if (str[i] < 0)
        {
            // 음수일 때는 Zn의 범위 더하기
            str[i] = str[i] + NUMBER_OF_ALPHABET;
        }
        else
        {
            // 양수일 때는 모듈러 연산
            str[i] = str[i] % NUMBER_OF_ALPHABET;
        }
        str[i] = str[i] + ASCII_BASE;
    }
    return;
}

// 곱셈 암호
void encrypt_mul(char *str, int key)
{
    if (find_mul_inverse(key) == -1)
    {
        printf("out of range\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - ASCII_BASE;
        str[i] = (str[i] * key) % NUMBER_OF_ALPHABET;
        str[i] = str[i] + ASCII_BASE;
    }
    return;
}

void decrypt_mul(char *str, int key)
{
    int inverse = find_mul_inverse(key);
    if (inverse == -1)
    {
        printf("out of range\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - ASCII_BASE;
        str[i] = (str[i] * inverse) % NUMBER_OF_ALPHABET;
        str[i] = str[i] + ASCII_BASE;
    }
    return;
}

// 아핀 암호
void encrypt_affine(char *str, int key_mul, int key_add)
{
    // 조건 체크
    if (find_mul_inverse(key_mul) == -1 || find_add_inverse(key_add) == -1)
    {
        printf("out of range\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - ASCII_BASE;
        str[i] = (str[i] * key_mul + key_add) % NUMBER_OF_ALPHABET;
        str[i] = str[i] + ASCII_BASE;
    }
    return;
}

void decrypt_affine(char *str, int key_mul, int key_add)
{
    int inverse_mul = find_mul_inverse(key_mul);
    int inverse_add = find_add_inverse(key_add);
    if (inverse_mul == -1 || inverse_add == -1)
    {
        printf("out of range\n");
        return;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = str[i] - ASCII_BASE;
        str[i] = str[i] - key_add;
        if (str[i] < 0)
            str[i] = str[i] + NUMBER_OF_ALPHABET;
        str[i] = (str[i] * inverse_mul) % NUMBER_OF_ALPHABET;
        str[i] = str[i] + ASCII_BASE;
    }
    return;
}

int main()
{
    system("clear");
    char str[] = "iamstudent";
    int key_mul = 7;
    int key_add = 2;
    printf("[plain] : %s\n[key for add] : %d\n[key for mul] : %d\n", str, key_add, key_mul);
    
    printf("\n[encrypt add]\n");
    encrypt_add(str, key_add);
    printf("cipher : %s\n", str);
    decrypt_add(str, key_add);
    printf("plain : %s\n", str);

    printf("\n[encrypt mul]\n");
    encrypt_mul(str, key_mul);
    printf("cipher : %s\n", str);
    decrypt_mul(str, key_mul);
    printf("plain : %s\n", str);

    printf("\n[encrypt affine]\n");
    encrypt_affine(str, key_mul, key_add);
    printf("cipher : %s\n", str);
    decrypt_affine(str, key_mul, key_add);
    printf("plain : %s\n", str);
    return 0;
}