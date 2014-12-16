#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100;
int main()
{
    int dp[MAXN][MAXN], a[MAXN], b[MAXN];
    int i, j, k, l, n, m, cases;
    cin >> cases;
    while(cases --)
    {
        cin >> n>> m;
        for(i = 0; i < n; i ++)
        cin>> a[i];

        for(i = 0; i < m; i ++)
        cin>> b[i];

        memset(dp, 0, sizeof(dp));
        for(i = 1; i < n; i ++)
        {
            for(j = 1; j < m; j ++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                if(a[i] == b[j])
                continue;

                for(k = i - 1; k >= 0; k --)
                {
                    if(a[k] == b[j])
                    break;
                }
                for(l = j - 1; l >= 0; l --)
                {
                    if(a[i] == b[l])
                    break;
                }

                if(k > 0 && l> 0)
                dp[i][j] = max(dp[i][j], dp[k - 1][l - 1] +1);

                if(k == 0 && l == 0)
                dp[i][j] = max(dp[i][j], 1);
            }
        }
        cout << 2 * dp[n - 1][m - 1]<< endl;
    }
}
