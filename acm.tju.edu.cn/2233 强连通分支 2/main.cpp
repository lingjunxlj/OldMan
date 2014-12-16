#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 10001;

vector<int>g[maxn];
vector<int>gb[maxn];

int n,mk[maxn],list[maxn],num;
int color[maxn],col;
int times[maxn];
int in_d[maxn];
int ans[maxn];

void back(int v)
{
        mk [v]=1;
        color[v] = col;

        for(int u = 0;u < gb[v].size(); u++)
            if(!mk [gb[v][u]])
            back(gb[v][u]);
}

void dfs(int u)
{
        mk [u]=1;
        for(int v=0;v < g[u].size();v++)
            if(!mk [g[u][v]])
            dfs(g[u][v]);

        list [num--] = u;
}

void scc()
{
        memset(mk,0,sizeof(mk));
        num=n;
        int i;
        for(i = 1; i <= n; i++)
            if(!mk[i])
            dfs(i);

        memset(mk,0,sizeof(mk));

        for(i = 1; i <= n; i++)
            if(!mk [list[i]])
            {
                back(list[i]);
                col++;
            }
}
int main()
{

        int m;
        int i, j;
        int a, b;
        int Max;

        while(scanf("%d %d", &n, &m))
        {
                if(n == 0 && m ==0 )break;

                col = 1;
                for(i = 1; i <= n; i++)
                {
                    g[i].clear();
                    gb[i].clear();
                }

                memset(color, 0, sizeof(color));
                memset(in_d, 0, sizeof(in_d));
                memset(ans, -1, sizeof(ans));

                for(i = 1; i <= n; ++i)
                    scanf("%d",&times[i]);
                while(m--)
                {
                    scanf("%d%d",&a,&b);
                    g[a].push_back (b);
                    gb[b].push_back(a);
                }

                scc();

                for(i = 1; i <= n; ++i)
                    for(j = 0; j < g[i].size(); ++j)
                        if(color[i] != color[g[i][j]])
                        in_d[color[g[i][j]]]++;


                for(i = 1; i <= n; ++i)
                {
                        if(in_d[color[i]])
                        ans[color[i]] = 0;

                        else if((times[i] < ans[color[i]]) || ans[color[i]] == -1)
                        ans[color[i]] = times[i];
                }
                Max = 0;
                for(i = 1; i < col; i++)
                    Max += ans[i];

                cout<<Max<<endl;
        }
        return 0;
}
