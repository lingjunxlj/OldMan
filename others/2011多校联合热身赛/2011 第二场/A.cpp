#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 10005
#define INF (1<<29)
struct node
{
	int b,c;
	node(){}
	node (int _b,int _c):b(_b),c(_c){}
};

vector<node>tree[MAXN];
int mnans[MAXN];
int mnleaf[MAXN];
int flag[MAXN];
void dfs(int x)
{
	mnans[x]=INF;
	mnleaf[x]=INF;
	int tmp=INF;
	flag[x]=1;
	if(tree[x].size()==1)
		mnleaf[x]=0;
	for(int i=0;i<tree[x].size();i++)
	{
		int v=tree[x][i].b;
		int d=tree[x][i].c;
		if(!flag[v])
		{
			dfs(v);
			if(mnans[v]<mnans[x])
				mnans[x]=mnans[v];
			if(mnleaf[v]+d<mnleaf[x])
			{
				tmp=mnleaf[x];
				mnleaf[x]=mnleaf[v]+d;
			}	
			else if(mnleaf[v]+d<tmp)
				tmp=mnleaf[v]+d;
		}
	}
	if(tmp!=INF)
		if(mnleaf[x]+tmp<mnans[x])
			mnans[x]=mnleaf[x]+tmp;
//	printf("%d %d %d\n",x,mnans[x],mnleaf[x]);
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=1;i<=n;i++)
			tree[i].clear();
		for(int i=1;i<n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			tree[a].push_back(node(b,c));
			tree[b].push_back(node(a,c));
		}
		memset(flag,0,sizeof(flag));
		dfs(1);
		printf("%d\n",mnans[1]);
	}
}
