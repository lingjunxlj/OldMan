#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[2005][1005], num[2005];
int w(int x)
{
    return (num[x] - num[x - 1]) * (num[x] - num[x - 1]);
}
int min(int x, int y)
{
    return x<y?x:y;
}
int main()
{
    int n, k;
    while(cin>>n>>k)
    {
        for (int i = 1; i <= n; i++)
            cin>>num[i];
        num[0] = 0;
        sort(num, num + n + 1);
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= k; j++)
                dp[i][j] = 2147483646;
        dp[0][0] = 0;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j * 2 <= i; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i - 2][j - 1] + w(i));
            }
        printf("%d\n",dp[n][k]);
    }
}
