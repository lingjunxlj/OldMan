/*
#include<cstdio>
#include<cstdlib>
#include<cstring>
int dp[10000*20];
int data[20];
int n;
int sum;
int target;
int main()
{
    int i, j;
    while(~scanf("%d",&n))
    {
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&data[i]);
            sum += data[i];
        }
        target = sum/2;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(i=0;i<n;i++)
            for(j=target;j>=data[i];j--)
                if(dp[j-data[i]])
                    dp[j] = 1;
        for(i=target;i>=0;i--)
            if(dp[i])
                break;
        printf("%d\n",sum-2*i);

    }
}
*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
int data[22];
int weight1;
int weight0;
int n;
int min;
void dfs(int index)
{
    if(index == n)
    {
        if(min > abs(weight0-weight1))
            min = abs(weight0-weight1);
    }
    else
    {
        weight0 += data[index];
        dsf(index+1);
        weight0 -= data[index];

        weight1 += data[index];
        dsf(index+1);
        weight1 -= data[index];
    }
}
int main()
{
    int cnum=1;
    while(~scanf("%d",&n))
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &data[i]);
        weight1 = 0;
        weight0 = 0;
        min = 10000000;
        dfs(0);
        printf("%d\n", min);
    }
}
