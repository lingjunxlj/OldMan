#include <cstdio>
int num[10001],flag[10001];
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int m;
        scanf("%d",&m);
        int i;
        for (i=0;i<10001;i++)
        flag[i]=0;
        for (i=0;i<m;i++)
        scanf("%d",&num[i]);
        for (i=0;i<m;i++)
        flag[num[i]]++;
        int max=0;
        for (i=0;i<10001;i++)
        if (flag[i]>max)
        max=flag[i];
        printf("%d\n",max);
    }
}
