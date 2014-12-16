#include <cstdio>
#include <cstdlib>
#include <cstring>
const int M = 105, INF = 1 << 30;
int mp[M][M], n, dist[M], flag[M], ans;
void dijkstra()
{
    int i, j, u, Min;
    for ( i = 1; i <= n; i++)
    {
        dist[i] = INF;
        flag[i] = 0;
    }
    dist[1] = 0;
    for ( i = 1; i <= n; i++ )
    {
        Min = INF;
        for ( j = 1; j <= n; j++ )
        if ( !flag[j] && dist[j] < Min )
        {
            Min = dist[j]; u = j;
        }
        if ( Min > ans ) ans = Min;
        flag[u] = 1;
        for ( j = 1; j <= n; j++ )
        if ( !flag[j] && dist[j] > dist[u] + mp[u][j] )
        dist[j] = dist[u] + mp[u][j];
    }
}

int main ()
{
    int i, j;
    char ch[100];
    while ( scanf("%d", &n) != EOF )
    {

        for ( i = 2; i <= n; i++ )
        {
            for ( j = 1; j < i; j++ )
            {
                scanf(" %s", ch);
                if ( ch[0] == 'x' )
                mp[i][j] = mp[j][i] = INF;
                else mp[i][j] = mp[j][i] = atoi(ch);
            }
        }
        for ( i = 1; i <= n; i++ )
        mp[i][i] = 0;
        ans = 0;
        dijkstra();
        printf("%d\n", ans);
        }
    }
