#include <cstdio>
#include <cmath>
#include <cstring>
#define INF 0x7fffffff
#define N 201
int x, y, z,n,m;
int dis[N][N];
int dp()
{
    int i, j, k;
    int temp, b[N][N];

    b[1][2] = dis[1][2];
    for (j=3; j<=n; j++)
    {
        for (i=1; i<=j-2; i++)
            b[i][j] = b[i][j-1] + dis[j-1][j];

        b[j-1][j] = INF;
        for (k=1; k<=j-2; k++)
        {
            temp = b[k][j-1] + dis[k][j];
            if (temp < b[j-1][j])
                b[j-1][j] = temp;
        }
    }

    b[n][n] = b[n-1][n] + dis[n-1][n];

    return b[n][n];
}

int main()
{
    int i, j;
    int ans;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        memset (dis, 0x7ffff,sizeof(dis));
        for (i=1; i<=m; i++)
        dis[i][i] = 0;

        for (i=1; i<=m; i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            dis[x][y] = z;
            //dis[y][x] = z;
        }


        ans = dp();

        printf("%d\n", ans);
    }
}
