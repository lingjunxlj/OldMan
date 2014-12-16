#include <cstdio>
int GCD(int a,int b)
{
    return b?GCD(b,a%b):a;
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m))
    {
        if (n==0&&m==0)
        break;
        n+=2;
        m++;
        int gcd=GCD(n,m);
        printf("%d %d\n",m/gcd,n/gcd);
    }
}
