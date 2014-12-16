#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 1501;
int pos[MAX];
int f1[MAX], f2[MAX], size[MAX];
int root;
int n;

struct Edge
{
    int rt;
    int ch;
}edge[MAX];

void dfs( int now )
{
    int i, v;
    f1[now] = 1;
    f2[now] = 0;
    if( size[now] == 0 )
    return;

    for( i = pos[now];; i++ )
    {
        if( edge[i].rt != now )
        break;
        v = edge[i].ch;
        dfs( v );
        f1[now] += min( f1[v], f2[v] );
        f2[now] += f1[v];
    }
}

int main()
{
    while( scanf("%d", &n ) != EOF )
    {
        int i, j, sum, u, v, num;
        sum =1;
        for( i = 1; i <= n; i++ )
        {
            scanf("%d:(%d)", &u, &num );
            pos[u] = sum;
            size[u] = num;
            for( j = 1; j <= num; j++ )
            {
                scanf("%d", &v );
                edge[sum].rt = u;
                edge[sum].ch = v;
                sum++;
            }
        }
        root = 0;
        dfs( root );
        printf("%d\n", min( f1[root], f2[root] ) );
    }
}
