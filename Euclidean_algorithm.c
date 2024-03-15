#include <stdio.h>
#include <stdlib.h>

// a와 b의 최대 공약수를 찾는다.
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// 확장 유클리드 알고리즘. 베주 항등식을 기반으로 하는듯
int ex_gcd(int a, int b, int *s, int *t)
{
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int q, r, ss, tt;

    while (r2 != 0)
    {
        q = r1 / r2;
        r = r1 % r2;
        ss = s1 - q * s2;
        tt = t1 - q * t2;

        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = ss;
        t1 = t2;
        t2 = tt;
    }
    *s = s1;
    *t = t1;
    return r1;
}

void ex_gcd_b(int a, int b, int *s, int *t)
{
    int r1 = a, r2 = b;
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;
    int q, r, ss, tt;

    while (r2 != 0)
    {
        q = r1 / r2;
        r = r1 % r2;
        ss = s1 - q * s2;
        tt = t1 - q * t2;

        r1 = r2;
        r2 = r;
        s1 = s2;
        s2 = ss;
        t1 = t2;
        t2 = tt;
    }
    *s = s1;
    *t = t1;
}

int find_mul_inverse(int n, int b)
{
    int s, t = 0;
    ex_gcd_b(n, b, &s, &t);
    if ((s * n + b * t) != 1)
        return -1;

    if(t < 0)
        return (t%n+n);
    else
        return t%n;
}

int main()
{
    int a, b, n; // a는 b의 곱셈에 대한 역원. n은 최소 잉여 집합의 크기(mod n)
    n = 100;
    b = 23;
    a = find_mul_inverse(n, b);

    printf("result : %d", a);
}