#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
#define V 10005
#define E 100005
vector<int> vec[V];
int id[V],pre[V],low[V],s[V],stop,cnt,scnt;
int n,m;
vector<int> g[V];
int uN,vN;
int xM[V],yM[V];
bool chk[V];
struct edge
{
	int x,y;
}e[E];
void tarjan(int v,int n)
{
	int t,minc=low[v]=pre[v]=cnt++;
	vector<int>::iterator pv;
	s[stop++]=v;
	for(pv=vec[v].begin();pv!=vec[v].end();++pv)
	{
		if(-1==pre[*pv])
		    tarjan(*pv,n);
		if(low[*pv]<minc)
		    minc=low[*pv];
	}
	if(minc<low[v])
	{
		low[v]=minc;
		return ;
	}
	do
	{
		id[t=s[--stop]]=scnt;
		low[t]=n;
	}while(t!=v);
	++scnt;
}
void solve()
{
	stop=cnt=scnt=0;
	memset(pre,-1,sizeof(pre));
	for(int i=0;i<n;i++)
	    if(-1==pre[i])
	        tarjan(i,n);
}
bool SearchPath(int u)
{
	int v;
	for(v=0;v<g[u].size();v++)
	    if(!chk[g[u][v]])
	    {
			chk[g[u][v]]=true;
			if(yM[g[u][v]]==-1||SearchPath(yM[g[u][v]]))
			{
				yM[g[u][v]]=u;xM[u]=g[u][v];
				return true;
			}
		}
	return false;
}
int MaxMatch()
{
	int u,ret=0;
	memset(xM,-1,sizeof(xM));
	memset(yM,-1,sizeof(yM));
	for(u=0;u<uN;u++)
	    if(xM[u]==-1)
	    {
			memset(chk,false,sizeof(chk));
			if(SearchPath(u))
			    ret++;
		}
	return ret;
}
int main()
{
	int i,j;
	int cas;
	int ans;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		    vec[i].clear();
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&e[i].x,&e[i].y);
			e[i].x--;e[i].y--;
			vec[e[i].x].push_back(e[i].y);
		}
		solve();
		//cout<<scnt<<endl;
		for(i=0;i<=scnt;i++)
		    g[i].clear();
		for(i=0;i<m;i++)
			if(id[e[i].x]!=id[e[i].y])
			    g[id[e[i].x]].push_back(id[e[i].y]);
		uN=vN=scnt;
		printf("%d\n",scnt-MaxMatch());
	}
	return 0;
}
