#include <cstdio>
int root[100001];
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
    int n,m,i,k;

    scanf("%d %d %d",&n,&m,&k);

        for (i=0;i<=n;i++)
        root[i]=i;
        while (m--)
        {
            int a,b;
            scanf("%d",&a);
            scanf("%d",&b);
            Union(a,b);
        }
        while (k--)
        {
            int t;
            scanf("%d",&t);
            if (find(1)==find(t))
            printf("Yes\n");
            else
            printf("No\n");
        }

}
