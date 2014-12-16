#include <cstdio>
int fri[10001],root[10001],sum[10001];
int find(int x)
{
    if (x!=root[x])
    root[x]=find(root[x]);
    return root[x];
}
int Union(int a,int b)
{
    int x,y;
    x=find(a);
    y=find(b);
    if (x==y)
    return 0;
    if (x>y)
    root[y]=x;
    if (x<y)
    root[x]=y;
    return 1;
}
int main()
{
    int i;
    for (i=0;i<10001;i++)
    root[i]=i;
    int n,m;
    scanf("%d %d",&n,&m);
    for (i=0;i<n;i++)
    scanf("%d",&fri[i]);
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        Union(x,y);
    }
    for (i=0;i<n;i++)
    {
        sum[find(i)]+=fri[i];
    }
    bool  flag=1;
    for (i=0;i<n;i++)
    {
        if (sum[i]!=0)
        {
            flag=0;
            printf("IMPOSSIBLE\n");
            break;
        }
    }
    if (flag)
    printf("POSSIBLE\n");
}
