#include <iostream>
#include <cstdio>
using namespace std;
int a[2010][2010], dp[2010];
int main()
{
    int i, j, n;

    for(i = 1; i <= 2000; i++)
    {
        a[i][1] = 1;
        a[i][i + 1] = 0;
        dp[i] = 1;
    }

    for(i = 2; i <= 2000; i++)
        for(j = 2; j <= i; j++)
        {
            a[i][j] = (j * a[i - 1][j] + a[i - 1][j - 1]) % 10000;
            dp[i] = (dp[i] + a[i][j]) % 10000;
        }

    while(cin>>n && n)
        printf("%04d\n", dp[n]);

    return 0;
}
