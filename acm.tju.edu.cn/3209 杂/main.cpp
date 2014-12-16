/*
1. dp[1-n],dp[n]=0(最后).
2. 对于dp[i],看i 和 i+1 谁高.如果i+1 高,dp[i]= i+1
3 .否则比较 i 与 dp[i] 的高度(回第2步) 直到越界
4.如果越界,dp[i]=0;
*/
#include <cstdio>
#include <cstring>
int n,cow[100005],dp[100005];
int main()
{
    int i, ans;
    scanf("%d", &n);
    for (i = 1;i <= n; i++)
        scanf("%d", &cow[i]);
    dp[n] = 0;
    for (i = n - 1; i > 0; i--)
    {
        ans = i + 1;
        while (ans > 0 && ans <= n && cow[i] >= cow[ans])
              ans = dp[ans];
        if (ans > n || ans < 1)
           ans = 0;
        dp[i] = ans;
    }
    for (i = 1; i <= n; i++)
        printf("%d\n", dp[i]);
    return 0;
}
