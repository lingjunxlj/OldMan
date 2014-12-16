#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cash, n, dp[100001], nk[1001], dk[1001], flag[100001];
int max (int a, int b)
{
    return a > b? a : b;
}
int main()
{
    while(scanf("%d", &cash) != EOF)
    {
        int Now = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &nk[i], &dk[i]);

        for (int i = 0; i <= cash; i++)
            dp[i] = 0;

        for (int i = 0; i <= cash; i++)
            flag[i] = 0;

        flag[0] = 1;

        for (int i = 1; i <= n; i++)
            for (int j = Now; j >= 0; j--)
            {
                if (flag[j])
                {
                    for (int k = 1; k <= nk[i]; k++)
                    {
                        int temp = j + k * dk[i];
                        if (temp <= cash)
                        {
                            Now = max(Now, temp);
                            flag[temp] = 1;
                        }

                    }
                }
            }
        printf("%d\n", Now);
        end:;
    }
}
