#include<cstdio>
int dp[15][29][29];
int d[6][2]=
{
    {-1, -1},
    { 0, -1},
    { 1,  0},
    { 1,  1},
    { 0,  1},
    {-1,  0}
};
int main()
{
    int n, t = 0;
    dp[0][14][14] = 1;
    for(int i = 1; i < 15; ++i)
        for(int x = 0; x < 29; ++x)
            for(int y = 0; y < 29; ++y)
            {
                int sum = 0;

                for(int l = 0; l < 6; ++l)
                if(x + d[l][0] >= 0 && x + d[l][0] < 29 && y + d[l][1] >=0 && y + d[l][1] < 29)
                sum += dp[i - 1][ x - d[l][0] ][ y - d[l][1] ];

                dp[i][x][y] = sum;
            }
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        printf("%d\n", dp[n][14][14]);
    }
    return 0;
}

