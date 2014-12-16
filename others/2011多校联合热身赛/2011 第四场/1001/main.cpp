#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include <queue>
using namespace std;
#define N 160005
#define typef int // type of flow
#define inf = 0x7f7f // max of flow
typef map[405][405];
int NN;
typef minf(typef a, typef b) { return a < b ? a : b; }
struct edge
{
	int u, v; typef cuv, cvu, flow;
	edge (int x=0, int y=0, typef cu=0,typef cv=0, typef f=0): u(x), v(y), cuv(cu), cvu(cv), flow(f) {}
	int other(int p) { return p == u ? v : u; }
	typef cap(int p)
	{
		return p == u ? cuv-flow : cvu+flow;
	}
	void addflow(int p, typef f) { flow += (p == u ? f : -f); }
};
struct vlist
{
	int lv, next[N], idx[2 * N], v;
	void clear(int cv)
	{
		v = cv; lv = -1;
		memset(idx, -1, sizeof(idx));
	}
	void insert(int n, int h)
	{
		next[n] = idx[h]; idx[h] = n;
		if (lv < h) lv = h;
	}
	int remove()
	{
		int r = idx[lv]; idx[lv] = next[idx[lv]];
		while (lv >= 0 && idx[lv] == -1) lv--;
		return r;
	}
	bool empty() { return lv < 0; }
};
struct network
{
	vector<edge> eg;
	vector<edge*> net[N];
	vlist list;
	typef e[N];
	int v, s, t, h[N], hn[2 * N], cur[N];
	void push(int);
	void relabel(int);
	void build(int, int);
	typef maxflow(int, int);
};
void network::push(int u)
{
	edge* te = net[u][cur[u]];
	typef ex = minf(te->cap(u), e[u]);
	int p = te->other(u);
	if (e[p] == 0 && p != t) list.insert(p, h[p]);
	te->addflow(u, ex); e[u] -= ex; e[p] += ex;
}
void network::relabel(int u)
{
	int i, p, mh = 2 * v, oh = h[u];
	for (i = net[u].size()-1; i >= 0; i--)
	{
		p = net[u][i]->other(u);
		if (net[u][i]->cap(u) != 0 && mh > h[p] + 1)
		mh = h[p] + 1;
	}
	hn[h[u]]--; hn[mh]++; h[u] = mh;
	cur[u] = net[u].size()-1;
	if (hn[oh] != 0 || oh >= v + 1)
	    return;
	for (i = 0; i < v; i++)
	    if (h[i] > oh && h[i] <= v && i != s)
		{
			hn[h[i]]--; hn[v+1]++; h[i] = v + 1;
		}
}
typef network::maxflow(int ss, int tt)
{
	s = ss; t = tt;
	int i, p, u; typef ec;
	for (i = 0; i < v; i++) net[i].clear();
	for (i = eg.size()-1; i >= 0; i--)
	{
		net[eg[i].u].push_back(&eg[i]);
		net[eg[i].v].push_back(&eg[i]);
	}
	memset(h, 0, sizeof(h)); memset(hn, 0, sizeof(hn));
	memset(e, 0, sizeof(e));
	e[s] = inf;
	for (i = 0; i < v; i++) h[i] = v;
	queue<int> q; q.push(t); h[t] = 0;
	while (!q.empty())
	{
		p = q.front(); q.pop();
		for (i = net[p].size()-1; i >= 0; i--)
		{
			u = net[p][i]->other(p);
			ec = net[p][i]->cap(u);
			if (ec != 0 && h[u] == v && u != s)
			{
				h[u] = h[p] + 1; q.push(u);
			}
		}
	}
	for (i = 0; i < v; i++)
	    hn[h[i]]++;
	for (i = 0; i < v; i++)
	    cur[i] = net[i].size()-1;
	list.clear(v);
	for (; cur[s] >= 0; cur[s]--)
	    push(s);
		while (!list.empty())
		{
			for (u = list.remove(); e[u] > 0; )
			{
				if (cur[u] < 0) relabel(u);
				else if (net[u][cur[u]]->cap(u) > 0 &&h[u] == h[net[u][cur[u]]->other(u)]+1)
				    push(u);
				else cur[u]--;
			}
		}
	return e[t];
}
void network::build {
	v = n; eg.clear();
	int i,j;
	/*int a, b, i; typef l;
	for (i = 0; i < m; i++)
	{
		cin >> a >> b >> l;
		eg.push_back(edge(a, b, l, 0)); // vertex: 0 ~ n-1
	}*/
	for(i=1;i<=NN;i++)
	{
		for(j=1;j<=NN;j++)
		{
			int node=(i-1)*NN+j;
			if(i<NN)
			{
				eg.push_back(edge(node, node+NN, map[i][j], 0));
				eg.push_back(edge(node+NN, node, map[i][j], 0));
			}
			if(j<NN)
			{
				eg.push_back(edge(node, node+1, map[i][j], 0));
				eg.push_back(edge(node+1, node, map[i][j], 0));
			}
		}
	}
	eg.push_back(edge(0, 1, inf, 0));
}
int main()
{
	int i,j;
	int cas;
	int res;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&NN);
		for(i=1;i<=NN;i++)
		{
			for(j=1;j<=NN;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		network g;
		g.build(NN*NN+1);
		res=g.maxflow(0,NN*NN);
		printf("%d\n",res);
	}
	return 0;
}
