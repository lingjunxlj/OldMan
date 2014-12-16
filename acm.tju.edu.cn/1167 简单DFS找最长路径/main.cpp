#include <cstdio>
#include <string>
int map[30][30], n, m, ans, sum;
bool flag[30][30];
void DFS(int temp)
{
    int i;
    for (i = 1; i <= m; i++)
    {
        if (map[temp][i]==1)
        {
            int u=i;
            if (flag[temp][u]==1)
            continue;
            flag[temp][u]=flag[u][temp]=1;
            sum++;
            if (ans < sum)
            ans = sum;
            DFS(u);
            sum--;
            flag[temp][u]=flag[u][temp]=0;
        }
    }
}
int main()
{
    while (scanf("%d %d", &n, &m))
    {

        if (n==0 && m==0)
        break;
        memset(map, 0, sizeof (map));
        int i, j, x, y;
        for (i=0;i<m;i++)
        {
            scanf("%d %d", &x, &y);
            x++;
            y++;
            map[x][y]=map[y][x]=1;
        }
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            memset(flag, 0, sizeof (flag));
            sum=0;
            DFS(i);
        }
        printf("%d\n",ans);
    }
}
