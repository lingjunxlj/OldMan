#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 20001;
long long sw[MAXN], sd[MAXN], a[MAXN], dp[MAXN], f[MAXN];
int work(int i, int j)
{
    return sw[i]*sd[i]-sw[j]*sd[j];
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int w, d;
        sw[1] = 0;
        for (int i = 1; i <= n; i++)
            scanf("%lld%lld", &sw[i], &sd[i + 1]);
        for (int i = 1; i <= n + 1; i++)
        {
            dp[i] = dp[i - 1] + sd[i] * sw[i - 1];
            sw[i] = sw[i] + sw[i - 1];
            sd[i] = sd[i] + sd[i - 1];
        }
        int l = 1, r = 1;
        a[l] = 1;
        for (int i = 2; i <= n; i++)
        {
            while(r - l + 1 > 1 && work(a[l], a[l + 1]) > sd[i] * (sw[a[l]] - sw[a[l+1]]))
                    l++;
            f[i] = dp[n + 1] - sw[a[l]] * (sd[i] - sd[a[l]]) - sw[i] * (sd[n + 1] - sd[i]);
            while (r > l && work(a[r-1],a[r])*(sw[a[r]]-sw[i]) > work(a[r],i)*(sw[a[r-1]]-sw[a[r]]))
                r--;
            r++;
            a[r] = i;
        }
        int ans = 0x7fffffff;
        for (int i = 2; i <= n; i++)
            if (f[i] < ans)
                ans = f[i];
        printf("%d\n", ans);
    }
}
