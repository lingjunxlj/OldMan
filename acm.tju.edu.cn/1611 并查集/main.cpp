#include <cstdio>
int root[30001];
int find(int x)
{
    while (root[x]!=x)
    x=root[x];
    return x;
}
int Union(int a,int b)
{
    int x,y;
    x=find(a);
    y=find(b);
    if (x==y)
    return 0;
    if (x>y)
    root[x]=y;
    if (x<y)
    root[y]=x;
    return 1;
}
int main()
{
    int n,m,i;

    while(scanf("%d %d",&n,&m))
    {
        if (n==0&&m==0)
        break;
        for (i=0;i<=n;i++)
        root[i]=i;
        while (m--)
        {
            int x,a,b;
            scanf("%d",&x);
            scanf("%d",&a);
            x--;
            while (x--)
            {
                scanf("%d",&b);
                Union(a,b);
            }
        }
        int sum=0;
        for (i=0;i<n;i++)
        if (find(i)==0)
        sum++;
        printf("%d\n",sum);
    }
}

