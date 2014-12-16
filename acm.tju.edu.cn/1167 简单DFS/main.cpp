#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector <int> v[26];

int n,m,ans,sum;
bool use[26],mark[26][26];

void dfs(int p)
{
    for(int i = 0;i < v[p].size();i ++)
    {
        int u = v[p][i];
        if(mark[p][u]) continue;
        mark[p][u] = mark[u][p] = 1;
        sum ++;
        if(ans < sum) ans = sum;
        dfs(u);
        sum --;
        mark[p][u] = mark[u][p] = 0;
    }
}
int main()
{
    int i,x,y;
    while(scanf("%d%d",&n,&m) && n + m)
    {
        for(i = 1;i <= n;i ++) {v[i].clear();use[i] = 0;}
        for(i = 1;i <= m;i ++)
        {
            scanf("%d%d",&x,&y);
            x ++ ,y ++;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        ans = 0;
        for(i = 1;i <= n;i ++)
        {
            memset(mark,0,sizeof(mark));
            sum = 0;
            dfs(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
