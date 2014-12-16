#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define maxn 310
int m,n;
int mp[maxn][maxn];
int stack[2][maxn];
vector<int>gp[2][maxn];
int dp[maxn][maxn];
int tp[2];
int dist[maxn];
int fa[maxn];
int flag[maxn];
struct Node
{
    int val;
    int pid;
}nd[maxn];
bool cmp(const Node & nd1, const Node& nd2)
{
    return nd1.val < nd2.val;
}
void solve(int st,int ed,int id)
{
    int i,j,k,dmin;
    memset(flag,0,sizeof(flag));
    memset(dist,0x3f,sizeof(dist));
    dist[st] = 0;
    for (i=0;i<n;i++)
    {
        k = -1;
        dmin = 0x3f3f3f3f;
        for (j=1;j<=n;j++)
        {
            if (dmin > dist[j] && flag[j] == 0)
            {
                k = j;
                dmin = dist[j];
            }
        }
        if (k == -1)
            break;
        flag[k] = 1;
        for (j=1;j<=n;j++)
        {
            if (flag[j] == 0 && dist[j] > dist[k] + mp[k][j])
            {
                dist[j] = dist[k] + mp[k][j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d\n", dist[i]);
    memset(flag,0,sizeof(flag));
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            if ( i != j && dist[j] == dist[i] + mp[i][j] )
            {
                flag[i] = flag[j] = 1;
                gp[id][j].push_back(i);
            }
        }
    }
    for (i=1;i<=n;i++)
    {
        if (flag[i])
        {
            nd[tp[id]].pid = i;
            nd[tp[id]].val = dist[i];
            tp[id]++;
        }
    }
    printf("tp[%d] == %d\n", id, tp[id]);
    sort(nd,nd+tp[id],cmp);
    for (i=0;i<tp[id];i++)
    {
        stack[id][i] = nd[i].pid;
        printf("stack[%d][%d] == %d\n", id, i, nd[i].pid);
    }
    return;
}
int main()
{
    int st1,ed1,st2,ed2;
    int a,b,c,i,j,ii,jj;
    while (scanf("%d%d",&n,&m))
    {
        if (m == 0 && n == 0)
            break;
        memset(mp,0x3f,sizeof(mp));
        for (i=1;i<=n;i++)
            mp[i][i] = 0;
        for (i=1;i<=n;i++)
        {
            gp[0][i].clear();
            gp[1][i].clear();
        }
        for (i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            mp[a][b] = mp[b][a] = min(mp[a][b],c);
        }
        scanf("%d%d%d%d",&st1,&ed1,&st2,&ed2);
        memset(tp,0,sizeof(tp));
        solve(st1,ed1,0);
        solve(st2,ed2,1);
        memset(dp,0,sizeof(dp));
        int pre_i,pre_j,tmp1,tmp2;
        for (i=0;i<tp[0];i++)
        {
            for (j=0;j<tp[1];j++)
            {
                tmp1 = gp[0][stack[0][i]].size();
                tmp2 = gp[1][stack[1][j]].size();
                if (tmp1 != 0 && tmp2 != 0)
                {
                    for (ii=0;ii<tmp1;ii++)
                    {
                        pre_i = gp[0][stack[0][i]][ii];
                        for (jj=0;jj<tmp2;jj++)
                        {
                            pre_j = gp[1][stack[1][j]][jj];
                            if (stack[0][i] == stack[1][j])
                            {
                                dp[stack[0][i]][stack[1][j]] = max(dp[stack[0][i]][stack[1][j]],dp[pre_i][pre_j] + 1);
                            }
                            else
                            {
                                dp[stack[0][i]][stack[1][j]] = max(dp[stack[0][i]][stack[1][j]],dp[stack[0][i]][pre_j]);
                                dp[stack[0][i]][stack[1][j]] = max(dp[stack[0][i]][stack[1][j]],dp[pre_i][stack[1][j]]);
                            }
                        }
                    }
                }
                else
                {
                    if (stack[0][i] == stack[1][j])
                    {
                        dp[stack[0][i]][stack[1][j]] = 1;
                    }
                }
            }
        }
        printf("%d\n",dp[ed1][ed2]);
    }
    return 0;
}
