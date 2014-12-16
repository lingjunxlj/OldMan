#include <cstdio>
int a[10005];
int main()
{
    int n, sum, ans, st, ed, x, y;
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        ans = sum = x = y = st = ed = a[0];
        for(int i = 1; i < n; i++)
        {
            if(sum > 0)
                sum += a[i], ed = a[i];
            else
                sum = a[i], st = ed = a[i];
            if(sum > ans)
            {
                ans = sum;
                x = st, y = ed;
            }
        }
        if(ans < 0)
            ans = 0, x = a[0], y = a[n - 1];
        printf("%d %d %d\n", ans, x, y);
    }
    return 0;
}
