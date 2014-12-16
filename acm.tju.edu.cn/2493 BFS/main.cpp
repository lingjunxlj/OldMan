#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int x[4] = { 0,  0, 1, -1};
int y[4] = { 1, -1, 0,  0};

int v[105][105], mark[105][105];
int dfs(int i, int j, int num)
{
    if(mark[i][j] || v[i][j] != num) return 0;
    mark[i][j] = 1;

    int sum, k;
    for(sum = 1, k = 0; k < 4; k++)
        sum += dfs(i + x[k], j + y[k], num);
    return sum;
}
int main()
{
    int n, i, j, a, b, fg, num;
    while(scanf("%d", &n), n)
    {
        memset(v, 0, sizeof(v));
        memset(mark, 0, sizeof(mark));

        for(i = 1; i < n; i++)
            for(j = 1; j <= n; j++)
            {
                scanf("%d%d", &a, &b);
                v[a][b] = i;
            }


        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                if(v[i][j] == 0)
                    v[i][j] = n;

        for(i = 0; i <= n + 1; i++)
        {
            mark[0][i] = 1;
            mark[n + 1][i] = 1;
            mark[0][i] = 1;
            mark[n + 1][i] = 1;
        }

        fg = 1;
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
            {
                if(mark[i][j] == 0)
                {
                    num = dfs(i, j, v[i][j]);
                    if(num != n)
                    {
                        fg = 0;
                        break;
                    }
                }
            }

        if(fg)
            printf("good\n");
        else
            printf("wrong\n");
    }
    return 0;
}
