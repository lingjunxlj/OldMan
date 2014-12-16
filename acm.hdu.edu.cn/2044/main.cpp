#include<cstdio>
__int64 sum[53][53];
int main()
{
    int i, j, a, b, t;
    for(i = 1; i <= 50; i++)
    {
        sum[i][i+1] = 1;
        sum[i][i+2] = 2;
        for(j = i + 3;j <= 50; j++)
        {
          sum[i][j] += (sum[i][j - 2] + sum[i][j - 1]);
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d", &a, &b);
        printf("%I64d\n", sum[a][b]);
    }
    return 0;
}
