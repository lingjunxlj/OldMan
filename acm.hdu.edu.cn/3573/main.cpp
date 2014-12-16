#include<cstdio>
int min( int a,int b )
{
    return a < b ? a : b;
}
int main()
{
    int  x,y,z,t,sum,n;
    scanf("%d", &n);
    for( int i = 1; i <= n; ++i )
    {
        sum = 0;
        scanf( "%d %d %d", &x, &y, &z );

        t = min( x / 2,z );
        x -= 2 * t,z -= t,sum += t;

        t = min( x / 2,y );
        x -= 2 * t,y -= t, sum += t;

        t = x / 3, x %= 3,sum += t;
        sum += ( x + y + z + 1 ) / 2;

        printf( "Case %d: %d\n",i,sum );
    }
    return 0;
}
