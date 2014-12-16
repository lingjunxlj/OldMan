#include<cstdio>
const int L = 101;
char hash[26];
int r, c, n;
int i, j, k;

char map[L][L];
char cmap[L][L];

void cpy()
{
    for( i = 0; i < r; i++ )
    {
        for( j = 0; j < c; j++ )
            map[i][j] = cmap[i][j];
    }
}


int round[4][2] =
{
     0,  1,
     1,  0,
     0, -1,
    -1,  0
};

void change()
{
    hash[ 'R' - 'A' ] = 'S';
    hash[ 'S' - 'A' ] = 'P';
    hash[ 'P' - 'A' ] = 'R';
    bool flag = 1;

    while( n-- )
    {
        flag = 0;

        for( i = 0; i < r; i++ )
        {
            for( j = 0; j < c; j++ )
            {
                int tr, tc;

                for( k = 0; k < 4; k++ )
                {
                    tr = i + round[k][0];
                    tc = j + round[k][1];
                    if( tr >= 0 && tr < r && tc >= 0 && tc < c )
                    {
                        if( hash[ map[tr][tc] - 'A' ] == map[i][j] )
                        {
                            cmap[i][j] = map[tr][tc];
                            flag = 1;
                            break;
                        }
                    }
                }

                if( k == 4 )
                {
                    cmap[i][j] = map[i][j];
                }
            }
        }

        cpy();

        if( !flag )
        {
            break;
        }
    }
}

int main()
{
    //freopen("a.txt", "r", stdin);
    //freopen("b.txt", "w", stdout);

    int t;

    scanf( "%d", &t);
    while( t-- )
    {
        scanf( "%d %d %d", &r, &c, &n );
        getchar();

        for( i = 0; i < r; i++ )
        {
            for( j = 0; j < c; j++ )
            {
                scanf( "%c", &map[i][j] );
            }
            getchar();
        }
        change();

        for( i = 0; i < r; i++ )
        {
            for( j = 0; j < c; j++ )
                printf( "%c", map[i][j] );

            putchar('\n');
        }
        if (t != 0)
        putchar('\n');
    }
    return 0;
}
