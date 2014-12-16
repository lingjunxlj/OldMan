#include <cstdio>
#include <string>
#define maxn 105
int nx, ny, job_num;
int g[maxn][maxn];
int ans;
int sx[maxn], sy[maxn], cx[maxn], cy[maxn];
int path(int u)
{
    sx[u] = 1;
    int v,i;
    for(v = 1;v <= ny; v++)
        if(g[u][v]>0 && !sy[v])
        {
            sy[v]=1;
            if(!cy[v] || path(cy[v]))
            {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
      return 0;
}
int main()
{
    int i, j, k, l;
    while(scanf("%d",&nx),nx)
    {
        scanf("%d %d", &ny, &job_num);
        memset(g, 0, sizeof(g));
        for(k = 0; k < job_num; k++)
        {
            scanf("%d %d %d", &l, &i, &j);
            g[i][j] = 1;
        }
        ans = 0;
        int i, j;
        memset(cx, 0, sizeof(cx));
        memset(cy, 0, sizeof(cy));
        for(i = 1;i <= nx; i++)
        if(!cx[i])
        {
            memset(sx, 0, sizeof(sx));
            memset(sy, 0, sizeof(sy));
            ans += path(i);
        }
        printf ("%d\n",ans);
    }
}
