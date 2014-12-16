#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int father[20005];
int rank[20005];
int hash[20005];
void make_set(int n)
{
    for (int i=1;i<=n;i++)
    {
        father[i] = i;
    }
}
int find_set(int x)
{
    if (father[x]==x)
        return x;
    return father[x]=find_set(father[x]);
}

void Union(int x, int y)
{
    x = find_set(x);
    y = find_set(y);

    father[x] = y;
}

int main()
{
    int n, m;
    while(scanf("%d",&n, &m) != EOF)
    {
        make_set(n);

        int tp1, tp2;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d %d",&tp1, &tp2);
            Union(tp1, tp2);
        }
        for (int i = 1; i <= n; i++)
            hash[i] = 0;
        int sum
        for (int i = 1; i <= n; i++)
        {

        }
    }

    return 0;
}
