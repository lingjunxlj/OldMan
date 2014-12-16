#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    long long a, b;
    while(scanf("%lld %lld", &a, &b) != EOF)
    {
         printf("%lld\n", a>=b?(a-b):(b-a));
    }
    return 0;
}
