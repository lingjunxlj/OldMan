#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int x[8] = { 0,  0, 1, -1, 1, -1, -1,  1};
int y[8] = { 1, -1, 0,  0, 1,  1, -1, -1};

char v[1005][1005];
int  mark[1005][1005];
int n, m;
int dfs(int i, int j)
{
    if(mark[i][j] || v[i][j] == '*' || i < 0 || i > n - 1 || j < 0 || j > m - 1)
        return 0;
    mark[i][j] = 1;

    int sum, k;
    for(sum = 1, k = 0; k < 8; k++)
        sum += dfs(i + x[k], j + y[k]);
    //printf("%d--\n",sum);
    return sum;
}
int main()
{
    int i, j, a, b, fg, num;
    cin>>m>>n;
    {
        memset(v, '*', sizeof(v));
        memset(mark, 0, sizeof(mark));

        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
                cin>>v[i][j];

        fg = 0;
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++)
            {
                if(mark[i][j] == 0)
                {
                    num = dfs(i, j);
                    if(num > fg)
                    {
                        fg = num;

                    }
                }
            }

        printf("%d\n", fg);
    }
    return 0;
}
