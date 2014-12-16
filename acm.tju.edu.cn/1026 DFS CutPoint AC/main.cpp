#include <cstdio>
#include <cstdlib>
#include <cstring>
const int M = 105;
int mp[M][M], flag[M], deg[M], low[M], n, cnt, cutp[M], ans;

void dfs(int u) {
     int i;
     deg[u] = low[u] = cnt++;
     for ( i = 1; i <= n; i++ )
         if ( mp[u][i] )
         {
              if ( !flag[i] )
              {
                flag[i] = 1;
                dfs(i);
                if ( low[u] > low[i] )
                low[u] = low[i];
                if ( ( deg[u] == 1 && deg[i] != 2 )|| ( deg[u] != 1 && low[i] >= deg[u] ) )
                cutp[u] = 1;
             }
            else
            {
                if ( low[u] > deg[i] )
                low[u] = deg[i];
            }
        }
}

int main ()
{
    int i, x, y;
    char ch;
    while ( scanf("%d", &n), n )
    {
          memset(flag, 0, sizeof(flag) );
          memset(mp, 0, sizeof(mp) );
          memset(deg, 0, sizeof(deg) );
          memset(low, 0, sizeof (low) );
          memset(cutp, 0, sizeof (cutp) );
          scanf("%d", &x);
          while ( x ) {
          scanf("%d%c", &y, &ch);
          mp[x][y]= mp[y][x] = 1;
          if ( ch == '\n' )
             scanf("%d", &x);
    }

    flag[1] = 1;
    cnt = 1;
    dfs(1);

    for ( ans = 0, i = 1; i <= n; i++ )
        if ( cutp[i] == 1) ans++;
    printf("%d\n", ans);
    }
    return 0;
}
