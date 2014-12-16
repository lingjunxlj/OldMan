#include <iostream>
#include <cstdio>
using namespace std;
const int INF = 1000000;
int n, m;
int map[105][105];
int lowcost[105], s[105];
void PRIM()
{
    int flag = 0;
    for(int i = 1; i <= n; i++)
    {
        lowcost[i]=map[1][i];
        s[i]=0;
    }
    s[1] = 1;
    int u, k;
    int ans = 0;
    for(int i = 1; i < n; i++)
    {
        int min = INF;
        for(int j = 1; j <= n; j++)
        {
            if(!s[j] && lowcost[j] < min)
            {
                min = lowcost[j];
                u = j;
            }
        }
        k = 0;
        for(int j = 1; j <= n; j++)
        {
            if(s[j] &&min == map[u][j])
                k++;
        }
        s[u] = 1;
        if(k > 1)
        {
            printf("Not Unique!\n");
            return;
        }
        ans += min;
        for(int j = 1; j <= n; j++)
            if(!s[j] && map[u][j] < lowcost[j])
                lowcost[j] = map[u][j];
    }
    printf("%d\n", ans);
}
int main()
{
int ca;
    cin>>ca;
    while(ca--)
    {
        cin>>n>>m;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                map[i][j] = INF;
        for(int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            map[u][v] = map[v][u] = w;
        }
        PRIM();
    }
    return 0;
}
