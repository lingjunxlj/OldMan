#include <cstdio>
int a[12];
int nul(int n)
{
    int i,sum=1;
    for (i=1;i<=n;i++)
    sum*=i;
    return sum;
}
int main()
{
    int i;
    for (i=0;i<12;i++)
    a[i]=nul(i);
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        if (n<0)
        break;
        if (n==0)
        {
            printf("NO\n");
            continue;
        }
        int k=11;
        while (n>=0&&k>=0)
        {
            if (n>=a[k])
            n-=a[k];
            k--;
        }
        if (n==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
}

