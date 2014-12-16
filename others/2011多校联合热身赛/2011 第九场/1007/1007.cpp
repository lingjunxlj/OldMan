#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int vis[10011];
int hash1[10011];
int hash2[10011];
int hash3[10011];
int hash4[10011];
vector <int> map1[10011];
vector <int> map2[10011];
int Max, flag;
void dfs1(int st, int pre, int num)
{
    if (vis[st])
    {
        flag = 1;
        return;
    }
    Max++;

    vis[st] = 1;
    for (int i = 0; i < map1[st].size(); i++)
    {
        int u = map1[st][i];
        if (u == pre)
            continue;
        //if (!vis[u])
        {
            dfs1(u, st, num + 1);
        }
    }
}
void dfs2(int st, int pre, int num)
{
    if (vis[st])
    {
        flag = 1;
        return;
    }
    Max++;

    vis[st] = 1;
    for (int i = 0; i < map2[st].size(); i++)
    {
        int u = map2[st][i];
        if (u == pre)
            continue;
        //if (!vis[u])
        {
            dfs2(u, st, num + 1);
        }
    }
}
int main()
{
    int t, x = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, m1;
        scanf("%d %d", &n, &m);
        memset(vis, 0, sizeof(vis));
        memset(hash1, 0, sizeof(hash1));
        memset(hash2, 0, sizeof(hash2));
        memset(hash3, 0, sizeof(hash3));
        memset(hash4, 0, sizeof(hash4));


        for (int i = 0; i <= n; i++)
        {
            map1[i].clear();
            map2[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            map1[a].push_back(b);
            map1[b].push_back(a);
        }

        scanf("%d %d", &n, &m1);

        for (int i = 0; i < m1; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            map2[a].push_back(b);
            map2[b].push_back(a);
        }

        if (m1 != m)
        {
             printf("Case #%d: NO\n", x++);
             continue;
        }
        if (n == 2 && m1 == m)
        {
            printf("Case #%d: YES\n", x++);
            continue;
        }

       for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                Max = 0;
                flag = 0;
                dfs1(i, i, 1);
                if (flag)
                    hash2[Max]++;
                else
                    hash1[Max]++;
            }
        }
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                Max = 0;
                flag = 0;
                dfs2(i, i, 1);
                if (flag)
                    hash4[Max]++;
                else
                    hash3[Max]++;
            }
        }
        int temp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (hash1[i]!= hash3[i] || hash2[i]!= hash4[i])
            {
                temp = 1;
                break;
            }
        }
        if (temp)
            printf("Case #%d: NO\n", x++);
        else
            printf("Case #%d: YES\n", x++);
    }
}
