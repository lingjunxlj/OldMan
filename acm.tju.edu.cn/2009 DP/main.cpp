#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int n, a[1001], dp[1001][1001];
int main()
{
     int t = 0;
     while(scanf("%d", &n), n)
     {
           int i,j,k;
           for(i = 1; i <= n; i++)
           scanf("%d", &a[i]);

           memset(dp, 0, sizeof(dp));

           for(i = 1; i < n; i++)
           dp[i][i + 1] = abs(a[i] - a[i+1]);

           for(k = 4; k <= n; k += 2)
               for(i = 1; i <= n - k + 1; i++)
               {
                    j = i + k - 1;
                    if(a[j] <= a[i+1])
                         dp[i][j] = max(dp[i][j], dp[i + 2][j] + a[i] - a[i + 1]);

                    if(a[i] < a[j - 1])
                         dp[i][j] = max(dp[i][j], dp[i][j - 2] + a[j] - a[j - 1]);

                    if(a[i + 1] < a[j])
                         dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[i] - a[j]);

                    if(a[i] >= a[j - 1])
                         dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + a[j] - a[i]);

               }
           t++;

           printf("In game %d, the greedy strategy might lose by as many as %d points.\n", t, dp[1][n]);
     }
     return 0;
}



