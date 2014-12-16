#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
const int M = 100005;
int n, v;
int ans[M], f[M];
int main()
{
    int i, j, k, g, p, gp, pv;

    while (scanf ("%d %d", &n, &v) != EOF)
    {
        memset(ans, 0, sizeof(ans));
        memset(f, 0, sizeof(f));

        for (i = 0; i < n; i++)
        {
            scanf ("%d %d", &p, &g);

            for (j = v; j >= p; j--)
            f[j] = ans[j - p];

            for (j = 0; j < g; j++)
            {
                scanf ("%d %d", &gp, &pv);

                for (k = v; k >= gp + p; k--)
                {
                    f[k] = max(f[k], f[k-gp] + pv);
                }

            }

            for (j = v; j >= p; j--)
            ans[j] = max(ans[j], f[j]);
        }
        printf ("%d\n", ans[v]);
    }
}
