#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int inf = 147483648 ;
int dp[11][101];
int map[11][101];
int ans[101];
int min(int a, int b)
{
    return a < b? a:b;
}
int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &map[i][j]);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = inf;

        for (int i = 0; i < n; i++)
            dp[i][m - 1] = map[i][m - 1];
        //cout<<1<<endl;

        for (int j = m - 1; j >= 0; j--)
            for (int i = 0; i < n; i++)
            {
                dp[i][j - 1] = min( min(dp[i-1>=0?i-1:i-1+n][j], dp[i][j]), dp[(i+1)%n][j]) + map[i][j-1];
            }
        //cout<<1<<endl;

        int minm = inf;
        for (int i = n - 1; i >= 0; i--)
        {
            if (minm >= dp[i][0])
            {
                minm = dp[i][0];
                ans[0] = i;
            }

        }
        //cout<<ans[0]<<"ans[0]"<<endl;
        for (int j = 0; j < m - 1; j++)
        {
            int ans1 = inf, ans2 = inf, ans3 = inf;

            if (dp[ans[j]][j] - map[ans[j]][j] == dp[ans[j]][j+1])
                ans1 = ans[j];

            if(dp[ans[j]][j] - map[ans[j]][j]==dp[(ans[j]+1)%n][j+1])
                ans2 = (ans[j]+1)%n;

            if(dp[ans[j]][j] - map[ans[j]][j]==dp[(ans[j]-1)>=0?(ans[j]-1):n+(ans[j]-1)][j+1])
                ans3 = (ans[j]-1) >= 0?(ans[j]-1): n + (ans[j]-1);

            if (ans1 <= ans2)
                ans[j + 1] = ans1;
            else
                ans[j + 1] = ans2;


            if(ans[j + 1] >= ans3)
                ans[j + 1] = ans3;
        }
        printf("%d", ans[0]+1);
        for (int i = 1; i < m; i++)
            printf(" %d", ans[i] + 1);
        printf("\n");

        printf("%d\n", minm);
    }
}
