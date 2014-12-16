#include <cstring>
#include <cstdio>
#define INF 0x1f1f1f1f
#define M 100
int map[M][M], dis[M];
bool flag[M];
void prim(int n, int s)
{
    int i, j, k, md, temp, sum;
    memset(flag, false, sizeof(flag));

    for(i = 1; i <= n; i++)
        dis[i] = map[s][i];

    dis[s] = 0, flag[s] = true, sum = 0;

    for(i = 1; i < n; i++)
    {
        md = INF;

        for(j = 1; j <= n; j++)
        {
            if(!flag[j] && dis[j] < md)
            {
                md = dis[j];
                temp = j;
            }
        }

        flag[temp] = true;
        sum += md;

        for(j = 1; j <= n; j++)
        {
            if(!flag[j] && map[temp][j] < dis[j])
                dis[j] = map[temp][j];

        }
    }
    printf("%d\n", sum);
}
int main()
{
    int i, j, k, m, n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0)
            break;

        for(i = 1; i <= n; i++)
            for(j = 1;j <= n; j++)
            {
                scanf("%d", &map[i][j]);

                if(map[i][j] < 0)
                    map[i][j] = map[j][i] = INF;

            }
            prim(n, 1);
        }
}
