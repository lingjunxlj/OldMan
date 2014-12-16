#include <iostream>
#include <cstdio>
using namespace std;
int w[1001], c[1001];
int dp[1000001];
int max(int a, int b)
{
    return a>b? a:b;
}
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n, v;
        cin>>n>>v;

        for (int i = 0; i < n; i++)
            cin>>w[i];
        for (int i = 0; i < n; i++)
            cin>>c[i];
        for (int j = 0; j <= v; j++)
            dp[j] = 0;
        for (int i = 0; i < n; i++)
            for (int j = v; j >= c[i]; j--)
                dp[j] = max(dp[j], dp[j - c[i]] + w[i]);
        cout<<dp[v]<<endl;
    }
}
