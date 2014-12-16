#include<math.h>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<limits.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 10005
vector<int>peo[MAX];//原图
vector<int>fpeo[MAX];//原图所有边反向的图
int cost[MAX],n,m,cnt,block[MAX],in_d[MAX],res[MAX],num,list[MAX];
//cost[i]:通知第i个人的花费，block[i]:第i个点属于缩点后的哪个点
//in_d：缩点后每个点的入度，res:结果，
bool f[MAX];
void dfs(int i)
{
    int j;
    f[i]=1;
    block[i]=cnt;
    for(j=0;j<peo[i].size();j++)
    {
	    if(!f[peo[i][j]])
	    dfs(peo[i][j]);
	}
	list[num--]=i;//list:dfs原图时点的倒序
}
void fdfs(int i)
{//dfs反向边的图
    int j;
    f[i]=1;
    block[i]=cnt;
    for(int j=0;j<fpeo[i].size();j++)
    {
	    if(!f[fpeo[i][j]]) fdfs(fpeo[i][j]);
	}
}
void scc()
{
 	    int i;
        memset(f,0,sizeof(f));
        num=n;//num：计数，递减地记录dfs点的顺序

        for(i=1;i <= n; i++)
            if(!f[i])
            dfs(i);

        memset(f,0,sizeof(f));

        for(i=1;i <= n; i++)
            if(!f[list[i]])
            {
                fdfs(list[i]);
                cnt++;
            }
		//按dfs点顺序的倒序dfs反向边的图
}
int main()
{
    int i,j,k,a,b,ans;
    while(scanf("%d%d",&n,&m),n||m)
    {
	    for(i=1;i<=n;i++)
	    {
			peo[i].clear();
			fpeo[i].clear();
        }
        memset(res,-1,sizeof(res));
        memset(in_d,0,sizeof(in_d));
        memset(block,0,sizeof(block));

		for(i=1;i<=n;i++) scanf("%d",&cost[i]);
		while(m--)
		{
	        scanf("%d%d",&a,&b);
	        peo[a].push_back(b);
	        fpeo[b].push_back(a);
		}
  		cnt=1;//cnt：记数，第几个缩点
  		scc();

  		for(i = 1; i <= n; i++)
            for(j = 0; j < peo[i].size(); j++)
                if(block[i] != block[peo[i][j]])
                    in_d[block[peo[i][j]]]++;

        for(i = 1; i <= n; i++)
        {
 	        if(in_d[block[i]])
 	        res[block[i]] = 0;

            else if((cost[i] < res[block[i]]) || res[block[i]] == -1)
            res[block[i]] = cost[i];
        }
        ans=0;
        for(i=1;i<cnt;i++) ans+=res[i];
        printf("%d\n",ans);
	}
    return 0;
}
