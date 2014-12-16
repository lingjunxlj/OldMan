#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 1000010
int n, m, k, h1, h2, t1, t2, now, ans, delta;
struct node
{
    int x;
    int pos;
}q1[maxn], q2[maxn], tmp;
int main()
{
    while (~scanf("%d %d %d", &n, &m, &k))
    {
        h1 = h2 = ans = now = 0, t1 = t2 = -1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &tmp.x);
            tmp.pos=i;
            while (h1 <= t1 && q1[t1].x <= tmp.x)
                t1--;
            q1[++t1] = tmp;

            while (h2 <= t2 && q2[t2].x >= tmp.x)
                t2--;
            q2[++t2] = tmp;

            while (q1[h1].x - q2[h2].x > k)
                if (q1[h1].pos < q2[h2].pos)
                {
                    now = q1[h1].pos;
                    h1++;
                }
                else
                {
                    now = q2[h2].pos;
                    h2++;
                }
            if (q1[h1].x - q2[h2].x <= k && q1[h1].x - q2[h2].x >= m)
                ans= ans>i-now?ans:i-now;
        }
        printf("%d\n", ans);
    }
    return 0;
}
