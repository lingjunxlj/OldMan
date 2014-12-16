#include <cstdio>
long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}
inline long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
long long eular(long long n)
{
    long long ret=1,i;

    for (i=2;i*i<=n;i++)
    if (n%i==0)
    {
        n/=i,ret*=i-1;
        while (n%i==0)
        n/=i,ret*=i;
    }
    if (n>1)
    ret*=n-1;
    return ret;
}
int main()
{
    //freopen("a.txt","w",stdout);
    long long i;
    long long sum = 0;
    long long n;

    while (scanf("%d", &n),n)
    {
        sum = 0;
        for (i = 1; i <= n; i++)
        sum = (sum + i)%1000000007;
        printf("%lld-----sum\n",sum);
        //sum = (1 + n) * n / 2 %1000000007;
        sum = (sum - n*eular(n)/2%1000000007)%1000000007;
        if (sum >= 0)
        {
            if ((sum-n) >= 0)
            printf("%lld\n",(sum-n)%1000000007);
            else
            printf("%lld\n",-(sum-n)%1000000007);

        }

        else
        {
            if ((sum+n) >= 0)
            printf("%lld\n",(sum+n)%1000000007);
            else
            printf("%lld\n",-(sum+n)%1000000007);

        }

    }
}
