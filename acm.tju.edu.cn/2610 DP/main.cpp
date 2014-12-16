#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXV =  2120;
bool flag[MAXV+1];
int prime[MAXV+1];
int size;
long long dp[MAXV][MAXV];
void genPrime(int max)
{
    memset(flag, true, sizeof(flag));
    for(int i = 2; i <= max / 2; i++)
    {
        if(flag[i])
        {
            for(int j = i << 1 ; j <= max; j += i)
            {
                flag[j] = false;
            }
        }
    }
    for(int i = 2 ; i <= max; i++)
    {
        if(flag[i])
        {
            prime[size++] = i;
        }
    }
}
int main()
{
    genPrime(MAXV);
    memset( dp, 0, sizeof(dp) );
    int k, i, j;

    dp[0][0] = 1;

    for (i = 0; i < size; i++)
        for (j = 1120-prime[i]; j >= 0; j--)
            for (k = 14; k > 0; k--)
            dp[k][ j+prime[i] ] += dp[k-1][j];

    int n, m;
    while (scanf("%d %d", &n, &m))
    {
        if (n==0 && m == 0)
        break;
        printf("%lld\n",dp[m][n]);
    }
}
