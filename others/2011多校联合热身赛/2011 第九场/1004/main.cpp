#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

const int N = 100000;
const int mol = 1000000007;

int a[N], p[N/10];
int p_fac[10], p_cnt[10], p_k;
int pf1[10], pc1[10], pk1;

int ans, m;

int prime2( int n)
{
    int i, j, k, t;
    for ( i = 2 , k = 0 ; i < n ; i ++ )
    {
        if( !a[i] )
            p[ k ++ ] = a[i] = i;
        for ( j = 0 ; j < k ; j ++ )
        {
            t = p[j] * i;
            if ( t >= n )
                break;
            a[ t ] = p[ j ];
            if( i % p[j] == 0 )
                break;
        }
    }
    return k;
}

// 要求 n > 1
void fac_break( int n, int p_fac[], int p_cnt[], int &p_k )
{
    if( n < N ){
        int t ;
        p_k = p_cnt[ 0 ] = 0;
        while( n != 1 )
        {
            t = p_fac[ p_k ] = a[n];
            while( n % t == 0 )
            {
                n /= t , p_cnt[ p_k ] ++ ;
            }
            p_k ++;
            p_cnt[ p_k ] = 0;
        }
    }
    else
    {
        p_k = p_cnt [ 0 ] = 0;
        for ( int i = 2 ; i * i <= n ; i ++ )
        {
            if( n % i == 0 )
            {
                p_fac[ p_k ] = i;
                while ( n % i == 0 )
                {
                    p_cnt [ p_k ] ++;
                    n /= i;
                }
                p_k ++;
                p_cnt[ p_k ] = 0;
            }
        }
        if( n != 1 ){
            p_fac[ p_k ] = n;
            p_cnt[ p_k ++ ] = 1;
        }
    }
}

int ruler( int n)
{
    fac_break( n , p_fac, p_cnt, p_k );
    for ( int i = 0 ; i < p_k ; i ++ ){
        n /= p_fac[ i ];
        n *= p_fac[ i ] - 1;
    }
    return n;
}

int mol_pow( int a, int b )
{
    int t = a, ans = 1;
    while( b ){
        if( b & 1 ){
            ans = 1ll * ans * t % mol;
        }
        t = 1ll * t * t % mol;
        b >>= 1;
    }
    return ans;
}

// 生成所有约数。 已经调用了 fac_break();
void make_div( int k, int val, int p_fac[], int p_cnt[], const int &p_k, const int &n,const int &m ){
    if( k == p_k ){

        int t = ruler( n / val );
        ans = ( 1ll * t * mol_pow( m, val ) % mol + ans ) % mol;

        return ;
    }
    int t = 1;
    for ( int i = 0 ; i <= p_cnt[ k ] ; i ++ )
    {
        make_div( k + 1, val * t , p_fac, p_cnt, p_k, n, m );
        t *= p_fac[ k ];
    }
}

int ext_gcd( int a,int b,int &x,int &y)
{
    if( b == 0 )
    {
        x = 1, y = 0;
        return a;
    }
    else
    {
        int d = ext_gcd( b, a%b, x, y );
        int t = x;
        x = y;
        y = t - a/b*y;
        return d;
    }
}

int ni( int n )
{
    int x, y;
    ext_gcd( n, mol, x, y );
    x %= mol;
    if( x < 0 )
        x += mol;
    return x;
}

int main()
{
    prime2( N );
    int i, j, k, n;
    int test ;
    scanf("%d",&test);
    int x = 1;
    while( test -- )
    {
        scanf("%d %d",&m, &n);

        ans = 0;
        fac_break( n, pf1, pc1, pk1 );
        make_div( 0, 1 , pf1, pc1, pk1, n, m );
        if( n % 2 ){
            ans = ( 1ll * n * mol_pow( m, n/2 + 1 ) % mol + ans ) % mol ;
        }
        else{
            ans = ( 1ll * n / 2 * mol_pow( m, n/2 + 1 ) % mol + 1ll * n / 2 * mol_pow( m, n / 2 ) % mol + ans ) % mol ;
        }
        //ni( n * 2 );
        ans = 1ll*ans*ni(n*2%mol)%mol;
        printf("Case #%d: %d\n",x++,ans);
    }
    return 0;
}
