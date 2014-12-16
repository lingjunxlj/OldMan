#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[1001][101], b[1001][101];
int n, m, r, c;
int main()
{
    while (cin>>n>>m>>r>>c)
    {
        if(n == 0 && m == 0 && r == 0 && c == 0)
        break;

        int i, j, x, y;
        for (i = 0; i < n; i++)
        cin>>a[i];
        memset(b, '0', sizeof(b));
        int count = 0;
        int k, h;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < m; j++)
            {
                if(a[i][j] == b[i][j])
                continue;
                if(i <= n - r && j <= m - c)
                {
                    for(k = i; k < i + r; k++)
                    {
                        for(h = j; h < j + c; h++)
                        {
                            b[k][h] = 1 - (b[k][h] - '0') + '0';
                        }
                    }
                    count++;
                }
                else
                {
                    printf("-1\n");
                    continue;
                }
            }
        }
        printf("%d\n", count);
    }

}
