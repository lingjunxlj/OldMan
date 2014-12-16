#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1001, inf = 0x7ffffff;
int dist[MAXN][MAXN], lowcast[MAXN];
bool flag[MAXN];
void dijkstra()
{
    int  min, u, i, j;
    memset(flag, 0, sizeof (flag) );
    memset(lowcast, 0x7f, sizeof (lowcast) );
    for(i = 0; i <= MAXN; i++)
    {
        lowcast[i] = dist[0][i];
    }
    flag[0] = 1;
    for ( i = 0; i <= MAXN; i++ )
    {
        min = inf;
        u = -1;
        for ( j = 0; j <= MAXN; j++ )
            if ( !flag[j] && lowcast[j] < min )
            {
                 min = lowcast[j];
                 u = j;
            }
        if ( u == -1 )
            break;
        flag[u] = 1;
        for ( j = 0; j <= MAXN; j++ )
            if ( !flag[j] && lowcast[j] > lowcast[u] + dist[u][j])
                lowcast[j] = lowcast[u] + dist[u][j];
    }
}
int main()
{
    int T, S, D;
    int a, b, time;
    while (cin>>T>>S>>D)
    {
        for (int i = 0; i <= MAXN; i++)
            for (int j = 0; j <= MAXN; j++){
                if (i != j)
                    dist[i][j] = inf;
                if(i == j)
                    dist[i][j] = 0;
            }
        for (int i = 0; i < T; i++){
            cin>>a>>b>>time;
            dist[a][b] = dist[b][a] = time;
        }
        for (int i = 0; i < S; i++){
            cin>>a;
            dist[0][a] = 0;
            dist[a][0] = 0;
        }
        dijkstra();
        int Min = inf;
        for (int i = 0; i < S; i++){
            cin>>a;
            if (lowcast[a] < Min)
                Min = lowcast[a];
        }
        cout<<Min<<endl;
    }
}
