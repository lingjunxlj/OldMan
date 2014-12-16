#include <cstdio>
long long num[10011];
int main()
{
    long long n;

    scanf("%lld",&n);
    while (n--)
    {
        long long sum=0,max,min;
        long long m,i;
        scanf("%lld",&m);
        for (i=0;i<m;i++)
        scanf("%lld",&num[i]);
        max=num[0];
        min=num[0];
        for (i=0;i<m;i++)
        {
            if (num[i]>max)
            max=num[i];
            if (num[i]<min)
            min=num[i];
        }
        sum=max-min;
        if (sum<0)
        printf("%lld\n",-sum);
        else
        printf("%lld\n",sum);

    }
}
