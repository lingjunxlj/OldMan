#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;

#define max(a,b) a>b?a:b;

const int N = 200010;
int val[N], n;
long long need;

int dpmax[N][20];

void init_rmq(int n)
{
    int i, j;
    for(i = 1; i <= n; i++)
         dpmax[i-1][0] = val[i];
    for(i = 1; (1 << i) <= n; i++)
        for(j = 0; j + (1 << i) <= n; j++)
             dpmax[j][i] = max(dpmax[j][i-1], dpmax[j+(1<<(i-1))][i-1]);
}

int query(int l, int r)
{
    int len = r - l + 1, lev;
     lev = (int)(log((double)len) / log(2.0));
    return max(dpmax[l-1][lev], dpmax[r-(1<<lev)][lev]);
}

int main()
{
    int i, j, l, r, eve;
    long long ans;
    while(scanf("%d%I64d", &n, &need))
    {
        if(n < 0 && need < 0) break;

         memset(val, 0, sizeof(val));
         memset(dpmax, 0, sizeof(dpmax));

        for(i = 1; i <= n; i++)
             scanf("%d", &val[i]);


         init_rmq(n);
        int tmp, m, per = -1, ps;
        ans = 0;
        for(i = 1; i <= n; i++)
        {

            eve = n / i;
            m = eve * i;

            if(per == eve)
            {
                for(j = ps + 1; j + eve - 1 <= m; j += eve)
                {
                    l = j;
                    r = j + eve - 1;
                    tmp = query(l, r);
                    ans += tmp;
                    if(ans > need)
                        break;
                }
            }
            else
            {
                ans = 0;
                for(j = 1; j + eve - 1 <= m; j += eve)
                {
                    l = j;
                    r = j + eve - 1;
                    tmp = query(l, r);
                    ans += tmp;
                    if(ans > need)
                        break;
                 }
            }
            if(ans > need)
                break;
            per = eve;
            ps = m;
        }
        if(ans > need)
            printf("%d\n", i);
        else
            printf("-1\n");
    }
    return 0;
}
