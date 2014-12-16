#include<vector>
#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX(a,b) ((a)>(b)?(a):(b))

int n,m,dp[208][208],a,b[208],hash[208],mark[208][208];
vector <int> map[208];

void dfs(int mm)
{
    int i,j,k;
    if(hash[mm]) return ;
    hash[mm] = 1;
    mark[mm][0] = 0;
    for(i=0;i<map[mm].size();i++)
        for(j=m;j>=0;j--)
            for(k=1;k<=m;k++)
            {
                if(mark[mm][j] == -1) continue;
                if(!hash[map[mm][i]])
                    dfs(map[mm][i]);
                int t = dp[map[mm][i]][k];
                if(t != -1)
                    mark[mm][j+k] = MAX(mark[mm][j+k],mark[mm][j] + t);
            }
    for(i=1;i<=m+1;i++)
        if(mark[mm][i-1] != -1)
            dp[mm][i] = mark[mm][i-1] + b[mm];
}

int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<=n;i++)
            map[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b[i]);
            map[a].push_back(i);
        }
    //    b[0] = 0;
        memset(hash,0,sizeof(hash));
        memset(mark,-1,sizeof(mark));
        memset(dp,-1,sizeof(dp));
        dfs(0);
        printf("%d\n",dp[0][m+1]);
    }
    return 0;
}
