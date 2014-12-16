#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

int dis[100001];

vector<int> edges[100001];
int f[100001];
int find(int x)
{
	if(f[x]!=x)
		f[x]=find(f[x]);
	return f[x];
}

void make(int a,int b)
{
	int a1=find(a);
	int b1=find(b);
	if(a1!=b1)
		f[b1]=a1;
}
int n,q;
void bfs(int root)
{
	dis[root]=0;
	queue<int> qu;
	qu.push(root);
	while(!qu.empty())
	{
		int now=qu.front();
		qu.pop();
		for(int i=0;i<edges[now].size();i++)
		{
			int next=edges[now][i];
			dis[next]=dis[now]+1;
			qu.push(next);
		}
	}
}


int main()
{
	while(scanf("%d%d",&n,&q), n)
	{
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
			edges[i].clear();
		}
		for( i=1;i<=n-1;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			make(a,b);
			edges[a].push_back(b);
		}
		int root=find(1);
		bfs(root);
		for(i=1;i<=q;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			if(dis[a]<=dis[b])
				printf("lxh\n");
			else
				printf("pfz\n");
		}
	}


	return 0;
}
