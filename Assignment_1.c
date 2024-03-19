/*
모듈로 𝑛의 값과 정수 𝑚이 입력되었을 때,
1. 정수 𝑚의 모듈로 덧셈 연산에 대한 역원 집합 𝒁𝒏
2. 모듈로 곱셈 연산에 대한 역원 집합 𝒁𝒏∗
을 구하시오
>입력 조건: 𝑛 ≥ 2, 𝑚 ≥ 2
>곱셈에 대한 역원 집합 𝒁𝒏∗은 확장 유클리드 알고리즘으로 계산한다.
>만약 곱셈 연산에 대한 역원 집합이 존재하지 않는다면“역원이 존재하지 않습니다.”라는 메시지를 출력할 것.
*/

#include <stdio.h>
#include <stdlib.h>

// 확장 유클리드 알고리즘 계산 함수
void ex_gcd(int n, int m, int *s, int *t)
{
    int r1 = n, r2 = m;
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

// 덧셈에 대한 역원 출력 함수
void find_add_inverse(int n, int m)
{
    if (n == m)
        // 자기 자신이 덧셈에 대한 역원일 때
        printf("0\n");
    else
    //(x+m) mod n = 0 mod n
    //(x+m) mod n = 0
    // x+m=n, x=n-m
        printf("%d\n", n - m);
    return;
}

// 곱셈에 대한 역원 출력 함수
void find_mul_inverse(int n, int m)
{
    int s, t = 0;

    // sn + tm = gcd(n, m)
    // sn + tm = 1 (모듈러 곱셈 역원의 필요충분조건에 의해)
    // 확장 유클리드 알고리즘 연산을 통해 s와 t의 값 산출
    ex_gcd(n, m, &s, &t);

    // 필요충분조건 체크
    if ((s * n + t * m) != 1)
    {
        printf("not exist\n");
        return;
    }

    // (sn + tm) mod n = 1 mod n
    // sn mod n + tm mod n = 1
    // 0 + tm mod n = 1,
    // (a * b) mod n = 1 mod n = 1 을 만족하면 서로 곱셈에 대한 역원 관계가 되므로
    // t와 m은 역원 관계에 있다.
    // 단, Zn의 범위를 벗어났을 경우, 이에 대응시켜야 한다.
    if (t < 0)
        // 피제수인 t가 음수인 경우 나머지인 r이 음수가 되므로 이를 양수로 바꾸어준다.
        printf("%d\n", (t % n + n));
    else
        // t를 Zn에 대응시킨다.
        printf("%d\n", (t % n));
    return;
}

int main()
{
    int n, m;
    while (1)
    {
        printf("input n m : ");
        scanf("%d %d", &n, &m); // 𝑛 ≥ 2, 𝑚 ≥ 2
        if (n < 2 || m < 2)
        {
            printf("out of range!\n");
        }
        else
        {
            printf("add inverse element: ");
            find_add_inverse(n, m);
            printf("mul inverse element : ");
            find_mul_inverse(n, m);
        }
    }
    return 0;
}