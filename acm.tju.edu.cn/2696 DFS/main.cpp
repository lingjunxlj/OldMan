#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int MAX = 20;
int n, m, k, ans, sum;
bool flag[MAX];
int num[MAX][MAX], x[MAX], y[MAX];
int dist(int a, int b, int c, int d)
{
    return abs((double)(a - c)) + abs((double)(b - d));
}
void DFS(int temp, int count, int sum)
{
    int i;
    if (count == k)
    {
        if (ans > sum + num[temp][0])
        ans = sum + num[temp][0];
        return;
    }
    for (i = 0; i <= k; i++)
    {
        if (flag[i] || sum + num[temp][i] > ans)
        continue;

        flag[i] = 1;
        DFS(i, count + 1, sum+ num[temp][i]);
        flag[i] = 0;
    }
}
int main()
{
    int t, i, j;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>x[0]>>y[0];
        cin>>k;

        for(i = 1;i <= k;i++)
        cin>>x[i]>>y[i];

        for (i = 0; i <= k; i++)
        {
            for (j = 0; j <=k; j++)
            num[i][j] = dist(x[i], y[i], x[j], y[j]);

            flag[i] = 0;
        }

        ans = 0x7ffff;
        memset(flag, 0, sizeof(flag));
        flag[0] = 1;
        DFS(0, 0, 0);

        printf("The shortest path has length %d\n",ans);
    }
}
