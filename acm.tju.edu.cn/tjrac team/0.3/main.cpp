#include <cstdio>
int num[100001];
int main()
{
    int x;
    scanf("%d",&x)
    while (x--)
    {
        int n;
        scanf("%d",&n);
        int sum=0,i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&num[i]);
            sum+num[i];
        }
        int m;
        scanf("%d",&m);
        char mvp[20];
        int a,b;
        scanf("%s",mvp);
        scanf("%d %d",&a,&b);
        if (mvp[0]=='I')
        {



