#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int flag;
vector <int> grap[100010];
int vis[1000010];
void dfs(int u, int pre, int col)
{
    if (flag)
        return;
    vis[u] = col;
    for (int i = 0; i < grap[u].size(); i++)
    {
        int v = grap[u][i];
        if (v == pre)
            continue;
        if (vis[v] == col)
        {
            flag = 1;
            return;
        }
        if (vis[v] == 0)
            dfs(v, u, -col);

    }
}
int main()
{
    int t;
    cin>>t;
    int x = 0;
    while(t--)
    {
        int n, m, s;
        cin>>n>>m>>s;
        for (int i = 0; i < n; i++)
            grap[i].clear();
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin>>a>>b;
            grap[a].push_back(b);
            grap[b].push_back(a);
        }
        memset(vis, 0, sizeof(vis));
        flag = 0;
        dfs(s, s, 1);
        x++;
        if (flag)
            printf("Case %d: YES\n", x);
        else
            printf("Case %d: NO\n", x);
    }
}
