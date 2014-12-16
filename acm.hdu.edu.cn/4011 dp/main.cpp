#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxx=100002;
int day[maxx];
long long dp[maxx][2];

long long min(long long a, long long b)
{
    return a < b ? a:b;
}

int main()
{
    int t,a,b,cnt;
    scanf("%d",&t);
    for(int i = 1; i <= t; i++)
    {
        scanf("%d %d %d", &cnt, &a, &b);
        for(int j = 0; j < cnt; j++)
            scanf("%d",&day[j]);

        dp[0][0] = (long long)(2*a+b);
        dp[0][1] = (long long)(a+b);
        for(int j = 1; j < cnt; j++)
        {
            dp[j][0] = min(dp[j-1][0] + 2 * a + b, dp[j-1][1]+(day[j] - day[j-1]) * b+a);
            dp[j][1] = min(dp[j-1][0] + a + b, dp[j-1][1]+(day[j] - day[j-1]) * b);
        }
        printf("Case #%d: ", i);
        printf("%I64d\n", min(dp[cnt-1][0], dp[cnt-1][1]+a));
    }
    return 0;
}
