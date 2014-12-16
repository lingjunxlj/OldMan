
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct type{
    long long cost;
    long long num;
}N[100001];

bool cmp(type a, type b)
{ return a.cost < b.cost; }
int min(int a, int b)
{
    return a < b? a : b;
}
int main()
{
    long long n, moneys, i, ans;
    scanf("%lld%lld",&n,&moneys);
    {
        ans = 0;
        for(i=0; i<n; ++i)
            scanf("%lld%lld",&N[i].cost,&N[i].num);
        sort(N,N+n,cmp);
        for(i = 0; i < n; ++i)
         {
             ans += min(moneys/N[i].cost, N[i].num);
             moneys -= min(moneys/N[i].cost, N[i].num) * N[i].cost;
         }

    }
    printf("%lld\n",ans);
    return 0;
}

