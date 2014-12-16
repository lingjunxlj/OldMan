#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long d[105];
long long l[5], c[5], a[105][105];
int main ()
{
    long long t, e, i, j, k, n, m, dis, x, y;
    scanf("%I64d", &t);
    for(e = 1; e <= t; e++)
    {
        memset(a, -1, sizeof(a));
        scanf("%I64d %I64d %I64d %I64d", &l[1], &l[2], &l[3], &l[4]);
        scanf("%I64d %I64d %I64d %I64d", &c[1], &c[2], &c[3], &c[4]);
        scanf("%I64d %I64d", &n, &m);
        for (i = 1; i <= n; i++)
        {
            scanf("%I64d", &d[i]);
            for (j = 1; j < i; j++)
            {
                dis = d[i] - d[j];
                if (dis < 0)
                    dis = 0 - dis;
                if (dis == 0)
                {
                    a[i][j] = 0;
                    a[j][i] = 0;
                }
                else if (dis <= l[1])
                {
                    a[i][j] = c[1];
                    a[j][i] = c[1];
                }
                else if (dis <= l[2])
                {
                    a[i][j] = c[2];
                    a[j][i] = c[2];
                }
                else if (dis <= l[3])
                {
                    a[i][j] = c[3];
                    a[j][i] = c[3];
                }
                else if (dis <= l[4])
                {
                    a[i][j] = c[4];
                    a[j][i] = c[4];
                }
            }
        }
        for (k = 1; k <= n; k++)
        {
            for (i = 1; i <= n; i++)
            {
                if (i == k || a[i][k] == -1)
                    continue;
                for (j = 1; j <= n; j++)
                {
                    if (a[k][j] == -1 || j == k || j == i)
                        continue;
                    if (a[i][j] == -1 || a[i][j] > a[i][k] + a[k][j])
                        a[i][j] = a[i][k] + a[k][j];
                }
            }
        }
        printf ("Case %I64d:\n",e);
        for (i = 1; i <= m; i++)
        {
            scanf("%I64d %I64d", &x, &y);

            if (x == y)
                printf ("The minimum cost between station %I64d and station %I64d is 0.\n", x, y);

            else if (a[x][y] != -1)
                printf ("The minimum cost between station %I64d and station %I64d is %I64d.\n", x, y, a[x][y]);

            else
                printf ("Station %I64d and station %I64d are not attainable.\n", x, y);
        }
    }
    return 0;
}
