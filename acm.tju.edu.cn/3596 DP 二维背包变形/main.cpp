#include <cstdio>
#include <cstring>
int opt[1001][1001];
int w[101], val[101];
int n, m, v, ans, t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d %d", &n, &m, &v);

        int i, j, k;
        for (i = 1; i <= n; i++)
        scanf("%d %d", &w[i], &val[i]);

        memset(opt, 0, sizeof (opt));

        for (i = 1; i <= n; i++)
            for (j = m; j >= 1; j--)
                if (j <= i)
                    for (k = v; k >= w[i]; k--)
                        if ( opt[j-1][k-w[i]] > 0 || (j == 1 && k == w[i]) )
                            opt[j][k] = opt[j-1][k-w[i]] + val[i] > opt[j][k]?opt[j-1][k-w[i]] + val[i] : opt[j][k];
        int max = -0x7fffffff;
        for (i = 0; i <= v; i++)
            if (opt[m][i] > max)
                max = opt[m][i];
        printf("%d\n",max);
    }
}
