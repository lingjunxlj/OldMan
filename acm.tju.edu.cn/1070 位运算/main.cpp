#include<cstdio>
#include<cstring>
int s[32768], use[32768], now[32768], data[16][32768];
int n, MAX, p, q, v, f, i, k;
int main()
{
    int i;
    for(n = 2; n <= 15; n++)
    {
        MAX = 1 << n;
        memset( use, 0, sizeof(use) );
        p = q = 0;
        s[p++] = 0;
        while(p > 0)
        {
            v = s[p - 1];
            for(f = 0; f < 2; f++)
                if(!use[(v << 1) + f])
                break;
            if(f >= 2)
            {
                now[q++] = v;
                p--;
            }
            else
            {
                use[(v << 1) + f] = 1;
                s[p++] = ( (v << 1) + f ) & ( (MAX >> 1) -1 );
            }
        }
        for(i = 0; i < MAX; i++)
        data[n][i] = ( now[MAX-i] << 1) | (now[MAX - i - 1] );
    }
    data[1][0] = 0;
    data[1][1] = 1;
    while(scanf("%d %d", &n, &k), n)
    printf("%d\n", data[n][k]);
}
