#include <iostream>
#include <cstdio>
using namespace std;
inline long long F1(long long k)
{
    if( k == 0 )
        return 0;
    return (long long) ( (long long) 1<<(k - 1) ) - 1;
}
inline long long F2(long long k )
{
    if( k == 0 )
        return 1;
    return (long long) 1<<(k - 1);
}
inline long long check( long long val )
{
    long long ans = 0, res = 0;
    int l = 0;
    for( ; ( (long long) 1<<l ) < val ; l ++ );
    for( int i = l; i >= 0; i -- )
    {
        if( val & ( (long long) 1<<i ) )
        {
            if( res & 1 )
                ans += F2(i);
            else
            {
                ans += F1(i);
                if( res > 0 )
                    ans ++;
            }
            res ++;
        }
    }
    if( res % 2 == 0 && val % 2 == 0 )
        ans ++;
    return ans;
}
int main ()
{
    int T;
    scanf("%d", &T);
    while( T -- )
    {
        int n;
        scanf("%d",&n);
        long long low = 1;
        long long high = (long long) 1 << 40;
        while( low <= high )
        {
            long long mid = (low + high) >> 1;
            if( check( mid ) >= n )
                high = mid - 1;
            else low = mid + 1;
        }
        printf("%lld\n",low);
    }
    return 0;
}
