#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int p[210], h[2010], c[210];
int dp[800010];
int max(int a, int b)
{
    return a>b ? a:b;
}
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        for (int i = 1; i <= m; i++)
            cin>>p[i]>>h[i]>>c[i];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; i++)
            for (int k = 1; k <= c[i]; k++)
                for (int j = n; j >=  p[i]; j--)
                    dp[j] = max(dp[j - p[i]] + h[i], dp[j]);
        cout<<dp[n]<<endl;
    }
}
