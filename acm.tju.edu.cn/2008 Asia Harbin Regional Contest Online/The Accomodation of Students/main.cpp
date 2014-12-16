#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int MAXN=210;

struct Node
{
    int v;
    int next;
}nodes[MAXN*MAXN];

int G[MAXN];
int Link[MAXN];
int n, m, alloc;
int vi[MAXN];

void add(int a,int b)
{
    alloc++;
    nodes[alloc].v = b;
    nodes[alloc].next = G[a];
    G[a] = alloc;
}
bool dfs(int u,int p)
{
    for(int son=G[u];son;son=nodes[son].next)
    {
        int v = nodes[son].v;
        if(v == p)
            continue;
        if(vi[v]!=-1)
        {
            if(vi[v] == vi[u])
                return false;//层次相差为偶数，即偶数回路
            continue;
        }
        vi[v] = 1 - vi[u];

        if(!dfs(v, u))
            return false;
    }
    return true;
}
bool find(int u)
{
    for(int son = G[u]; son; son = nodes[son].next)
    {
        int v = nodes[son].v;
        if(vi[v])
            continue;
        vi[v] = 1;
        if(!Link[v] || find(Link[v]))
        {
            Link[v] = u;
            return true;
        }
    }
    return false;
}
int main()
{
    //freopen("in","r",stdin);
    int a, b;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        alloc = 0;
        memset(G, 0, sizeof(G));

        for(int i = 0; i < m; i++)
        {
            scanf("%d %d", &a, &b);
            add(a, b);
            add(b, a);
        }
        memset(vi, -1, sizeof(vi));
        bool flag = false;
        for(int i = 1; i <= n; i++)
            if(vi[i] == -1)
            {
                vi[i] = 1;
                if(!dfs(i, i))
                {
                    flag = true;
                    break;
                }
            }
        if(flag)
        {
            printf("No\n");
            continue;
        }
        int ans = 0;
        memset(Link, 0, sizeof(Link));
        for(int i = 1; i <= n; i++)
        {
            memset(vi, 0, sizeof(vi));
            ans += find(i);
        }
        printf("%d\n", ans / 2);
    }
    return 0;
}
