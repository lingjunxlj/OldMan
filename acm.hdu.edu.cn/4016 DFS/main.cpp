#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long Max = 0x7fffffffffffffff;
long long num[50];
long long b[50];
long long ans;
int k, n;
void DFS(int now, int nu, long long Num)
{
    if (Num < ans)
        ans = Num;
    if (nu == k || now >= n + 1)
        return;
    long long s = Num&b[now];
    if (s >= ans)
        return;
    DFS(now + 1, nu + 1, Num&num[now]);
    DFS(now + 1, nu, Num);

}
int main()
{
    int t, x = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
            scanf("%I64d", &num[i]);
        sort(num + 1, num + n + 1);
        b[n] = num[n];
        for (int i = n-1; i >= 1; i--)
        {
            b[i] = num[i]&b[i + 1];
        }
        //cout<<Max<<endl;
        ans = Max;
        DFS(1, 0, Max);
        printf("Case #%d: %I64d\n", x++, ans);
    }
}
