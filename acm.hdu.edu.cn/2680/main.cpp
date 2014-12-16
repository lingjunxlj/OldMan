#include <iostream>
#include <cstdio>
#include <string>
#define INF 200000001
using namespace std;
int n;
int map[1010][1010], dist[1010];
void dij(int v0)
{
    int s[1010];
    int mindis, i, j, u;
    for(i = 1; i <= n; i++)
    {
        dist[i] = map[v0][i];
        s[i] = 0;
    }
    s[v0] = 1;
    for(i = 1;i <= n; i++)
    {
        mindis = INF;
        u = -1;
        for(j = 1;j <= n; j++)
        {
            if(s[j] == 0 && dist[j] < mindis)
            {
                u = j;
                mindis = dist[j];
            }
        }
        if(u == -1)
            break;
        s[u] = 1;
        for(j = 1; j <= n; j++)
        {
            if(s[j])
                continue;
            if(map[u][j] != INF && dist[u] + map[u][j] < dist[j])
                dist[j] = dist[u] + map[u][j];
        }
    }
}
int main()
{
    int i, j, m, s, w;
    while(scanf("%d %d %d", &n, &m, &s) != EOF)
    {
        int a, b, c;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                map[i][j] = INF;
        for(i = 1; i <= m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if(map[b][a] > c)
                map[b][a] = c;
        }
        dij(s);
        scanf("%d", &w);
        int res = INF;
        int t;
        for(i = 1; i <= w; i++)
        {
            scanf("%d", &t);
            if(dist[t] < res && dist[t] != -1)
                res = dist[t];
        }
        if(res == INF)
            printf("-1\n");
        else
            printf("%d\n", res);
    }
    return 0;
}
