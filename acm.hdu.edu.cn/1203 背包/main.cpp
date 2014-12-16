#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int w[10009];
double c[10009];
double dp[10000001];
int min(int a, int b)
{
    return a<b? a:b;
}
int main()
{
    int n, m;
    while (cin>>n>>m)
    {
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i <= m; i++)
            cin>>w[i]>>c[i];
        for (int i = 0; i <= n; i++)
            dp[i] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = n; j >= w[i]; j--)
                {
                    dp[j] = min(dp[j], dp[j - w[i]] * (1 - c[i]));
                }
        printf("%.1lf%%\n", (1 - dp[n]) * 100);
    }

}
