#include<iostream>
using namespace std;
const int maxn=305;
int map[maxn][maxn],nv[maxn],mv[maxn];
bool vst[maxn];
int n,m;
int dfs(int n_v)
{
    for(int i=1;i<=m;i++)
     {
        if(!vst[i]&&map[n_v][i]==1)
         {
            vst[i]=true;
            if(mv[i]==-1||dfs(mv[i])==1)
            {
                mv[i]=n_v;
                nv[n_v]=i;
                return 1;
            }
         }
     }
    return 0;
}
int main()
{
    int test;
    while(scanf("%d",&test)!=EOF)
    {
        while(test--)
        {
            memset(map,-1,sizeof(map));
            scanf("%d%d",&m,&n);
            for(int i=1;i<=m;i++)
            {
                int t;
                scanf("%d",&t);
                while(t--)
                {
                    int s;
                    scanf("%d",&s);
                    map[s][i]=1;
                }
            }
            int ans=0;
            memset(nv,-1,sizeof(nv));
            memset(mv,-1,sizeof(mv));
            for(int i=1;i<=n;i++)
            {
                if(nv[i]==-1)
                {
                    memset(vst,false,sizeof(vst));
                    if(dfs(i)==1) ans++;
                }
            }
            printf(ans==m?"YES\n":"NO\n");
        }
    }
    return 0;
}
