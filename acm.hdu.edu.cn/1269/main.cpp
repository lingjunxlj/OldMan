#include <cstdio>
unsigned int fa[10001], di[10001], n, m;
int find(unsigned int v)
{
    if(fa[v] != 1 && fa[v] != v)
        fa[v] = find(fa[v]);
    return fa[v];
}
int find1(int v)
{
    if(di[v] != 1 && di[v] != v)
        di[v] = find1(di[v]);
    return di[v];
}
void Union(unsigned int x,unsigned int y)
{
    if(x > 1) fa[x] = find(y);
    if(y > 1) di[y] = find1(x);
}
int judge()
{
 unsigned int i;
 for(i = 2; i <= n; i++)
    if(find(i) != 1)
        return 0;
 for(i = 2; i <= n; i++)
    if(find1(i) != 1)
        return 0;
 return 1;
}
int main()
{
    unsigned int x, y, i;
    while(scanf("%d %d", &n, &m), n)
    {
        for(i = 1; i <= n; i++)
        {
            fa[i] = i;
            di[i] = i;
        }
        while(m-- && scanf("%d %d", &x, &y))
            Union(x,y);
        if(judge())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
