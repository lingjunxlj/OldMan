#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int tt;
struct node
{
    int d;
    int t;
}q[100011];
int flag[100011];
bool cmp(node a, node b)
{
    return a.t > b.t;
}
int main()
{
    int x = 1;
    scanf("%d", &tt);
    while(tt--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &q[i].d, &q[i].t);
        sort(q, q + n, cmp);
        int sum = 0;
        int Max = q[0].d + q[0].t;
        sum = q[0].d;
        for (int i = 1; i < n; i++)
        {
            sum += q[i].d;
            if (sum + q[i].t > Max)
                Max = sum + q[i].t;
        }
        printf("Case %d: %d\n", x++, Max);
    }
}
