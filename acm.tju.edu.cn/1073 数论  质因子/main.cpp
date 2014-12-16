#include <cstdio>
#include <cmath>
bool Prime(long long n)
{
    long long i;
    for (i=2;i<=(long long)sqrt(n*1.0);i++)
    {
        if (n%i==0)
        return true;
    }
    return false;
}
int Sum(long long n)
{
    long long s=0;
    while (n>0)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}
int Sum1(long long n)
{
    long long i;
    if (!Prime(n))
    return Sum(n);
    for (i=(long long)sqrt(n*1.0);i>=2;i--)
    {
        if (n%i==0)
        return Sum1(i)+Sum1(n/i);
    }
}
int main()
{
    long long n;
    while (scanf("%lld",&n),n)
    {
        long long i;
        long long s1=0,s2=0;
        for (i=n+1;;i++)
        {
            if (Prime(i))
            {
                s1=Sum(i);
                s2=Sum1(i);
                if (s1==s2)
                {
                    printf("%lld\n",i);
                    break;
                }
            }
        }
    }
}
