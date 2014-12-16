#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[101][101];
int visit[101];
int n, m;
int DFS(int u)
{
    visit[u] = -1;
    for (int v = 0; v < n ; v++)
        if (map[u][v])
        {

            if (visit[v] < 0)
                return 0;
            else if (!visit[v] && !DFS(v))
                return 0;
        }
    visit[u] = 1;
    return 1;
}
int main()
{
    while (cin>>n>>m, n+m)
    {
        int  a, b, fg = 0;
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < m ; i++)
        {
            cin>>a>>b;
            map[a][b] = 1;
        }
        for (int i = 0; i < n ; i++)
            if (!visit[i])
                if (!DFS(i))
                    {
                        cout<<"NO"<<endl;
                        fg = 1;
                        break;
                    }
        if (!fg)
            cout<<"YES"<<endl;
    }
}

