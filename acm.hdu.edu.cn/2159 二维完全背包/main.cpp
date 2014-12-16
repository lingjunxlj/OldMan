#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[105], b[105], dp[105][105];
int max(int a, int b)
{
    return a>b ? a:b;
}
int main()
{
    int n, m, k, s, i;
    while (cin>>n>>m>>k>>s)
    {
        for (int i = 1; i <= k; i++)
            cin>>a[i]>>b[i];
        memset(dp, 0, sizeof(dp));
        for (i = 1; i <= m; i++)
        {
            for (int j = 1; j <= s; j++)
                for (int p = 1; p <= k; p++)
                    if (i >= b[p])
                        dp[i][j] = max(dp[i][j], dp[i-b[p]][j-1] + a[p]);
            if (dp[i][s] >= n)
                break;
        }
        cout<<(m - i)<<endl;
    }
}
