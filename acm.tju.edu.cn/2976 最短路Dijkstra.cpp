#include <cstdio>
#include <cstdlib>
#include <cstring>
const int N = 102, INF = 1 << 30;
int map[N][N], dist[N], flag[N], n, m;
int main () 
{
    int i, j, u, v, w;
    while ( scanf("%d %d", &n, &m), n) 
    {
        memset(map, 0x7f, sizeof(map) );
        for ( i = 0; i < m; i++ ) 
        {
            scanf("%d %d %d", &u, &v, &w);
            map[u][v] = map[v][u] = w; 
        }
        int  min, u;
        memset(flag, 0, sizeof (flag) );
        memset(dist, 0x7f, sizeof (dist) );
        dist[1] = 0;
        for ( i = 1; i <= n; i++ ) 
        {
            min = INF;
            for ( j = 0; j < n; j++ ) 
            if ( !flag[j] && dist[j] < min ) 
            {
                 min = dist[j];
                 u = j;
            }
            if ( u == n ) break;
            flag[u] = 1;  
            for ( j = 1; j <= n; j++ ) 
            if ( !flag[j] && dist[j] > dist[u] + map[u][j])
            dist[j] = dist[u] + map[u][j];  
        }
          printf("%d\n", dist[n] );
    }    
}
