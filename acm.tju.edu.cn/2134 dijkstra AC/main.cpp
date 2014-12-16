#include<cstdio>
int n, m;
double g[101][101], D[101];
bool use[101];
void dijstra()
{
    int i,j,u;
    for(i = 2;i <= n;i++)
    {
        D[i] = g[1][i];
        use[i] = 0;
    }
    use[1] = 1;
    for(i = 1;i < n;i++)
    {
        double temp = 0;
        for(j = 2;j <= n;j++)
        {
            if(!use[j] && temp < D[j])
            {
                temp = D[j];
                u = j;
            }
        }
        use[u] = 1;
        if(u == n)
        {
            printf("%.6lf percent\n",D[n]*100);
            break;
        }

        for(j = 2;j <= n;j++)
        {
            if(!use[j] && D[u]*g[u][j] > D[j])
                D[j] = D[u]*g[u][j];
        }
    }
}
int main()
{
    int i,j;
    int a,b,p;
    while(1)
    {
        scanf("%d",&n);

        if(n == 0)
            break;
        scanf("%d",&m);
        for(i = 1;i < n;i++)
        {
            for(j = i + 1;j <= n;j++)
            {
                g[i][j] = 0;
                g[j][i] = 0;
            }
            g[i][i] = 0;
        }
        for(i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&a,&b,&p);

            g[a][b] = p/100.0;
            g[b][a] = p/100.0;
        }
        dijstra();
    }
    return 0;
}
