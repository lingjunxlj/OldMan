#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[1100], num[11];
int sum, n;
int res;
int main()
{
    cin>>sum>>n;
    res = 0;

    for (int i = 1; i <= n; i++)
        cin>>num[i];
    memset (dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = sum; j >= num[i]; j--)
            for(int k = 1;k <= sum/num[i] + 1; k++)
            {
                if (j - k * num[i] >= 0)
                    dp[j] += dp[j - k * num[i]];
                else
                    break;
            }
    printf("%d\n", dp[n]);
}
