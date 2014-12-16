#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    int z;
    int d;
}block[1111];
bool cmp (node a, node b)
{
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y < b.y;
    return a.d > b.d;

}
long long dp[1111];
int main()
{
    int n;
    while(scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d %d", &block[i].x, &block[i].y, &block[i].z, &block[i].d);
            if (block[i].x < block[i].y)
            {
                int temp = block[i].x;
                block[i].x = block[i].y;
                block[i].y = temp;
            }
        }
        sort(block, block + n, cmp);
        long long Max = 0
        long long Maxdp = 0;
        for (int i = 0 ; i < n; i++)
        {
           dp[i] = block[i].z;
           Max = 0;
            for (int j = 0; j < i; j++)
            {
                if (block[i].d == 0 && block[j].x <= block[i].x && block[j].y <= block[i].y )
                    dp[i] = max(dp[i], dp[j] + block[i].z);
                if (block[i].d == 1 && block[j].x <= block[i].x && block[j].y <= block[i].y && (block[j].x < block[i].x || block[j].y < block[i].y))
                    dp[i] = max(dp[i], dp[j] + block[i].z);
                if (block[i].d == 2 && block[j].x < block[i].x && block[j].y < block[i].y )
                    dp[i] = max(dp[i], dp[j] + block[i].z);
            }

            if (Maxdp < dp[i])
                Maxdp = dp[i];


        }
        printf("%I64d\n", Maxdp);
    }
}
