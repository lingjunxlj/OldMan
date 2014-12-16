#include<cstdio>
int p[10005];
int find(int x)
{
    if(p[x] == x)
        return x;
    else return
        p[x] = find(p[x]);
}
int unite(int x, int y)
{
    x = find(x);
    y = find(y);

    if(x == y)
        return 1;
    else
    {
        p[x] = y;
        return 0;
    }
}
int main()
{
    int n, m, i, j, x, y, res;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        res = 0;
        for(i = 0; i < n; i++)
            p[i] = i;
        for(i = 1; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            res += unite(x, y);
        }
        printf("%d\n", res);
    }
    return 0;
}
