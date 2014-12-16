#include <cstdio>
const int M = 101;
int n, m, cnt, Max, dist[M];
struct node
{
    int u, v, cost;
} edge[M * 2];

void Add(int u, int v, int d )
{
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt++].cost = d;
}

int Bellman_Ford()
{
    int i, j, flag, u, v, d;
    for ( i = 0; i <= n; i++ )
    dist[i] = 0;

    for ( i = 0; i <= n; i++ )
    {
        for ( flag = j = 0; j < cnt; j++ )
        {
            u = edge[j].u;
            v = edge[j].v;
            d = edge[j].cost;
            if ( dist[v] > dist[u] + d )
            {
                dist[v] = dist[u] + d;
                flag = 1;
            }
        }


        if ( !flag )
        break;

        if ( i == n && flag )
        return 0;
    }
    return 1;
}
int main ()
{
    int i, j, a, b, k;
    char c[3];
    while ( scanf("%d", &n), n )
    {
        cnt = 0;
        scanf("%d", &m);
        Max = 0;
        for ( i = 0; i < m; i++ )
        {
            scanf(" %d %d %s %d", &a, &b, c, &k);

            if ( c[0] == 'g')
            Add( b + a + 1, a, -1 * ( k + 1) );

            else
            Add(a, a + b + 1, k - 1);
        }
        printf("%s\n", Bellman_Ford() ? "lamentable kingdom": "successful conspiracy" );
    }
}
