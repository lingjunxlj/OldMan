#include <iostream>
#include <cstdio>
using namespace std;
int root[10010];
int find(int p)
{
    while (root[p]!=p)
    p=root[p];
    return p;
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
    int n,m,k,i;
    while (scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
       for (i=0;i<=n;i++)
       root[i]=i;
        while (m--)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            Union(a,b);
        }
        while (k--)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if (find(x)==find(y))
            printf("YES\n");
            else
            printf("NO\n");
        }
    }
}
