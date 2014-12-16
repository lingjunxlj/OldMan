#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 41;
long long w[N], ans;
long long m;
int n, k;
void dfs(int x, long long s, int cnt)
{
    if (cnt > k || s > m)
        return;
    ans = max(ans, s);
    if (x >= n)
        return;
    dfs(x + 1 ,s + w[x], cnt + 1);
    dfs(x + 1 ,s, cnt);
}
int main()
{
    while (scanf("%d %I64d", &k, &m) == 2)
     {
         scanf("%d", &n);
         long long s = 0;
         for (int i = 0;i < n;i++)
             scanf("%I64d", &w[i]);

         sort(w, w + n);
         for (int i = n - 1;i >= n - k;i--)
             s += w[i];
         if (s <= m)
             printf("%I64d\n", s);
         else if (w[0] > m)
             printf("0\n");
         else
         {
             ans = 0;
             dfs(-1, 0, 0);
             printf("%I64d\n", ans);
         }
     }
     return 0;
 }
