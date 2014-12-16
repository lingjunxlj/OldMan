#include<cstdio>
#include<vector>
using namespace std;

#define MAX 1600
#define INF 0x7f7f7f

int dp[MAX][2];
vector<int> mp[MAX];

void dfs(int p,int fa)
{
   int s = mp[p].size();

   for(int i=0;i<s;i++)
   {
      if( mp[p][i] == fa ) continue;

      dfs(mp[p][i], p);
   }

   int sum = 0;

   for(int i=0;i<s;i++)//dp[p][1]
   {
      if( mp[p][i] == fa ) continue;

      sum += min(dp[ mp[p][i] ][0],
                  dp[ mp[p][i] ][1]);
   }

   dp[p][1] = sum + 1;
   //printf("dp[%d][1] = %d\n", p, dp[p][1]);

   sum = 0;

   for(int i=0;i<s;i++)//dp[p][0]
   {
      if( mp[p][i]==fa ) continue;

      sum += dp[ mp[p][i] ][1];
   }

   dp[p][0] = sum;

   //printf("dp[%d][0] = %d\n", p, dp[p][0]);
}

int main()
{
   int n,i,j;
   int u,v,k;

   while( scanf("%d", &n)!=EOF )
   {
      memset(dp,0x7f7f7f,sizeof(dp));
      for(i=0;i<=n;i++)
         mp[i].clear();

      for(i=1;i<=n;i++)
      {
         scanf("%d:(%d)", &u, &k);

         for(j=1;j<=k;j++)
         {
            scanf("%d", &v);

            mp[u].push_back(v);
            mp[v].push_back(u);
         }
      }

      dfs(0, -1);

      if( n==1 )
         printf("1\n");
      else
         printf("%d\n", min(dp[0][0], dp[0][1]) );
   }
}
