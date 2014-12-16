#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[35100];
int num[22];
int c, m;
int max(int x, int y)
{
    return x>y?x:y;
}
int main()
{
    cin>>c>>m;
    for (int i = 0; i < m; i++)
        cin>>num[i];

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < m; i++)
        for (int j = c; j >= num[i]; j--)
            if (dp[j - num[i]] + num[i] <= c)
                dp[j] = max(dp[j], dp[j - num[i]] + num[i]);


    printf("%d\n", dp[c]);

}
