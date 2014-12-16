#include <cstdio>
#include <cstdlib>
#include <cstring>
const int N = 1002, INF = 1 << 30;
int map[N][N], dist[N], flag[N], n, m, s, t;
int main () 
{
    int tt, i, j, u, v, w;
    scanf("%d", &tt);
    while ( tt-- ) 
    {
        scanf("%d %d %d %d", &n, &m, &s, &t);
        memset(map, 0x7f, sizeof(map) );
        for ( i = 0; i < m; i++ ) 
        {
            scanf("%d %d %d", &u, &v, &w );
            map[u][v] = map[v][u] = w;
        }
        int i, j, min, u;
        memset(flag, 0, sizeof(flag) );
        memset(dist, 0x7f, sizeof(dist) );
        dist[s] = 0;
        for ( i = 1; i <= n; i++ ) 
        {
            min = INF;
            for ( j = 1; j <= n; j++ )
            if ( !flag[j] && dist[j] < min ) 
            {
                 min = dist[j];
                 u = j;
            }
            flag[u] = 1;
            for ( j = 1; j <= n; j++ )
            if ( !flag[j] && dist[j] > dist[u] + map[u][j])
            dist[j] = dist[u] + map[u][j];
        }
        if ( dist[t] < INF ) 
        printf("%d\n", dist[t] );
        else 
        printf("-1\n") ;    
    }
}

