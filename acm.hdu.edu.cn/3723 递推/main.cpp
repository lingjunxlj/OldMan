#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int dp[10000][5001];
int main()
{
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = dp[1][1] = 1;
    dp[1][2] = 0;
    //dp[2][0] =
    for (int i = 2; i <= 100; i++)
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1];
            else if (j == i)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + dp[i - 1][j + 1];

        }
    for (int i = 1; i <= 100; i++)
        cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
}
