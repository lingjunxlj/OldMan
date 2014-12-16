#include<iostream>
#include<cstdio>
#include<cstring>
#define Inf 999999999
using namespace std;
int map[110][110],dis[110],vis[110];
int main()
{
    int t, n, a, b, c, min, sum, k;
    while(scanf("%d", &n), n)
    {
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(i == j)
                    map[i][j] = 0;
                else
                    map[i][j] = Inf;
        for(int i = 0; i < n * (n - 1) / 2; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &t);
            if(t)
                map[a][b] = map[b][a] = 0;
            else
                map[a][b] = map[b][a] = c;
        }
        memset(vis, 0, sizeof(vis));
        sum = 0;
        for(int i = 1; i <= n; i++)
            dis[i] = map[1][i];
        vis[1] = 1;
        for(int i = 1; i < n; i++)
        {
            min = Inf;
            for(int j = 1; j <= n; j++)
                if(!vis[j] && dis[j] < min)
                {
                    min = dis[j];
                    k = j;
                }
            vis[k] = 1;
            sum += dis[k];
            for(int j = 1; j <= n; j++)
                if(!vis[j] && dis[j] > map[k][j])
                    dis[j] = map[k][j];
        }
        printf("%d\n", sum);
    }
    return 0;
}
