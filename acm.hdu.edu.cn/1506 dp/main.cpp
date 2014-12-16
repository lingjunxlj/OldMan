#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn =  100001;
long long l[maxn], r[maxn], a[maxn];
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%I64d", &a[i]);
            l[i] = r[i] = i;
        }
        a[0] = a[n + 1] = -1;
        for (int i = 1; i <= n; i++)
            while(a[l[i] - 1] >= a[i])
                l[i] = l[l[i] - 1];
        for(int i = n; i >= 1; i--)
            while(a[r[i] + 1] >= a[i])
                r[i] = r[r[i] + 1];
        long long ans = 0;
        for (int i = 1; i <= n; i++)
            if (ans < a[i]*(r[i] - l[i] + 1))
                ans = a[i]*(r[i] - l[i] + 1);
        printf("%I64d\n", ans);
    }
}
