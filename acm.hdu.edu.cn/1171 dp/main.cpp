#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[250050];
int c[101], num[101];
int main()
{
    int N;
    while (cin>>N)
    {
        if (N < 0)
            break;
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin>>c[i]>>num[i];
            sum += c[i] * num[i];
        }
        int sum1 = sum/2;
        for (int i = 0; i <= sum1; i++)
            dp[i]=0;
        dp[0] = 1;
        for (int i = 0; i < N; i++)
            for (int j = num[i]; j >= 0; j--)
                for (int k = sum1 - c[i]; k >= 0; k--)
                {
                    if (dp[k])
                        dp[k + c[i]] = 1;
                }
        int i = sum1;
        while (!dp[i])
            i--;
        printf("%d %d\n", sum - i, i);
    }
}
