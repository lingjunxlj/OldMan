#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define typec unsigned int
#define inf 0x3ffffff
#define V 160001
#define E 700001
unsigned int n;
unsigned int S,T,N;
typec cost[E],dist[V];
unsigned int e,pnt[E],nxt[E],head[V],prev[V],vis[V];
struct qnode
{
	unsigned int v;typec c;
	qnode(unsigned int vv=0,typec cc=0):v(vv),c(cc){}
	bool operator<(const qnode& r)const {return c>r.c;}
};
void dijkstra(unsigned int n,unsigned int src)
{
	qnode mv;
	unsigned int i,j,k,pre;
	priority_queue<qnode> que;
	vis[src]=1;dist[src]=0;
	que.push(qnode(src,0));
	for(pre=src,i=1;i<n;i++)
	{
		for(j=head[pre];j!=-1;j=nxt[j])
		{
			k=pnt[j];
			if(vis[k]==0&&dist[pre]+cost[j]<dist[k])
			{
				dist[k]=dist[pre]+cost[j];
				que.push(qnode(pnt[j],dist[k]));
				prev[k]=pre;
			}
		}
		while(!que.empty()&&vis[que.top().v]==1)
		    que.pop();
		if(que.empty())
		    break;
		mv=que.top();que.pop();
		vis[pre=mv.v]=1;
	}
}
inline void addedge(unsigned int u,unsigned int v,typec c)
{
	pnt[e]=v;cost[e]=c;nxt[e]=head[u];head[u]=e++;
}
inline void init()
{
	unsigned int i,j;typec tmp;
	e=0;
	for (unsigned int i = 0; i < N; i++)
	{
	    head[i] = -1;vis[i] = 0; prev[i] = -1;
	}
	for(i=0;i<=N;i++)
	    dist[i]=inf;
	for(i=0;i<n;i++)
	    for(j=0;j<n;j++){
			scanf("%d",&tmp);
			unsigned int node=i*(n-1)+j+1;
			if(i==0&&j<n-1){
				addedge(S,node,tmp);
				addedge(node,S,tmp);
			}
			if(j==n-1&&i<n-1){
				addedge(S,node-1,tmp);
				addedge(node-1,S,tmp);
			}
			if(j==0&&i<n-1){
				addedge(node,T,tmp);
				addedge(T,node,tmp);
			}
			if(i==n-1&&j<n-1){
				addedge(node-(n-1),T,tmp);
				addedge(T,node-(n-1),tmp);
			}
			if(i>0&&i<n-1&&j>=0&&j<n-1){
				addedge(node-(n-1),node,tmp);
				addedge(node,node-(n-1),tmp);
			}
			if(j>0&&j<n-1&&i>=0&&i<n-1){
				addedge(node-1,node,tmp);
				addedge(node,node-1,tmp);
			}
		}
}
int main()
{
	unsigned int i,j;
	unsigned int cas;
	unsigned int ans;
	scanf("%d",&cas);
	while(cas--){
		unsigned int tmp;
		scanf("%d",&n);S=0;T=(n-1)*(n-1)+1;N=T+1;init();
		dijkstra(N,S);ans=dist[T];printf("%d\n",ans);
	}return 0;
}
