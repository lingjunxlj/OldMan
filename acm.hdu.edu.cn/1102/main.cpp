#include <cstdio>
#include <cstring>
#define  N  110
int  n,result;
int  map[N][N];
bool visite[N];
int  dis[N];

void  Prim()
{
    memset( visite, false, sizeof(visite) );
    visite[0] = true;  result = 0;

    for( int i = 0; i < n; ++i )
        dis[i] = map[0][i];
    for( int i = 1; i < n; ++i )
    {
        int min= 0x7ff, k;

        for( int j = 0; j < n; ++j )
            if( !visite[j] && dis[j]< min )
                min = dis[j], k = j;

        visite[k]= true;  result+= dis[k];
        for( int j= 0; j< n; ++j )
            if( !visite[j] && map[k][j] >= 0 && map[k][j] < dis[j] )
                dis[j] = map[k][j];
    }
}

int main()
{
    while( scanf("%d",&n)!= EOF )
    {
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                scanf("%d", &map[i][j] );

        int test;
        scanf("%d", &test);
        for( int i = 0; i < test; ++i )
        {
            int a, b;
            scanf("%d %d", &a, &b );

            map[a-1][b-1] = 0;
            map[b-1][a-1] = 0;
        }

        Prim();
        printf("%d\n", result );
    }

    return 0;
}
