#include<iostream>
using namespace std;
long long mod = 100000000, temp1, temp2, temp;
long long multi(long long n, long long d)
{
    temp1 = 0;
    temp2 = n;
    long long i, c;
    for(i = 2; i <= d; i++)
    {
        temp = temp2 * n;
        c = temp / mod;
        temp2 = temp % mod;
        temp1 = (temp1 * n) + c;
    }
}
int main()
{
    long long n,d;
    mod *= mod;
    while(scanf("%lld %lld", &n, &d))
    {
        if (n == 0 && d == 0)
        break;

        multi(n, d);

        if(d==0)
        printf("1\n");
        else if(temp1)
        printf("%lld%.16lld\n", temp1, temp2);
        else
        printf("%lld\n", temp2);
    }
}
