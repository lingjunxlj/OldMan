#include <cstdio>
#include <string>
int map[2000][2000], n, m, ans, sum, eu;
bool flag[2000][2000];
void DFS(int temp)
{
    int i;
    for (i = 1; i <= m; i++)
    {
        if (map[temp][i]!=0)
        {
            int u=i;
            if (flag[temp][u]==1)
            continue;
            flag[temp][u]=flag[u][temp]=1;
            sum += map[temp][u];
            if (ans < sum)
            {
                ans = sum;
                eu=u;
            }
            DFS(u);
            sum -= map[temp][u];
            flag[temp][u]=flag[u][temp]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    while (n--)
    {
        scanf("%d",&m);
        memset(map, 0, sizeof (map));
        int i, j, x, y, z;
        for (i=0;i<m-1;i++)
        {
            scanf("%d %d %d", &x, &y,&z);
            map[x][y]=map[y][x]=z;
        }
        ans = 0;
        {
            memset(flag, 0, sizeof (flag));
            sum=0;
            DFS(1);
        }
        {
            memset(flag, 0, sizeof (flag));
            sum=0;
            DFS(eu);
        }
        printf("%d\n",ans);
    }
}
