#include <cstdio>
int root[50001];
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
    if(x==y)
    return 0;
    if(x>y)
    root[x]=y;
    if(x<y)
    root[y]=x;
    return 1;
}
int main()
{
    int n,m,x,y,i,k=0;
    while (scanf("%d %d",&n,&m))
    {
        if (n==0&&m==0)
        break;
        k++;
        for (i=0;i<n;i++)
        root[i]=i;
        while (m--)
        {
            scanf("%d %d",&x,&y);
            Union(x,y);
        }

        int sum=0;
        for (i=0;i<n;i++)
        if (root[i]==i)
        sum++;
        printf("Case %d: %d\n",k,sum);
    }
}
