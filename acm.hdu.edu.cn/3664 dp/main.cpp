#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1000000007;
long long dp[1001][1001];
int n1, k1;
int main()
{
    dp[0][0] = 1;
    for (int n = 1; n < 1001; n++)
        for (int k = 0; k <= n; k++)
        {
            if (k == 0)
                dp[n][k] = dp[n - 1][k] * (k + 1) % mod;
            else
                dp[n][k] = (dp[n - 1][k] * (k + 1) + dp[n - 1][k - 1] * (n - k) ) % mod;
        }
    while (cin>>n1>>k1)
    {
        cout<<dp[n1][k1]<<endl;
    }

}
