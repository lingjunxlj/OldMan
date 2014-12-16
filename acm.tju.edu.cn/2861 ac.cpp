#include<cstdio>
#include<cmath>
long long calc(int n)
{
    long long t=(int)sqrt(n);
    long long ans=0;
    for(int i=1;i<=t;i++)
    ans+=n/i;
    return ans*2 - t*t;
}
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b),a&&b)
    printf("%lld\n",calc(b)-calc(a-1));
}

