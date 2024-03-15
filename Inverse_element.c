#include <stdio.h>
#include <stdlib.h>

// a와 b의 최대 공약수를 찾는다.
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int find_mul_inverse(int a, int b)
{
    
}

int main()
{
    int n = 26; // mod n
    int b = 11  //b에 대한 곱셈의 역원을 구해야 함.
    
}