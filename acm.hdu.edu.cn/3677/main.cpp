#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[10];
int main()
{
    int l, n, t, x = 0;
    while (scanf("%d", &l), l)
    {
        x++;
        scanf("%d %d", &n, &t);
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        sort(num, num + n);
        int ans = l/num[0] + (n - 1) * t;
        printf("Case %d: %d\n", x, ans);

    }
}
