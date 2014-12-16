#include <cstdio>
#include <cstring>
#define FOR(a,b) for(int i = a; i<= b; ++i)
#define INF 0x1f1f1f1f
#define MAXN 250
using namespace std;
int n,m,src,sink,num;
int cap[MAXN][MAXN],f[MAXN][MAXN],level[MAXN],q[MAXN];
inline bool dinic_bfs(){
	int queue[MAXN];
	memset(level,-1,sizeof(level));
	int head = 0,tail = 0;
	queue[tail++] = src;
	level[src] = 0;
	while(tail > head)
	{
		int tep = queue[head++];
		for(int i = 1;i <= n; ++i)
		{
			if(level[i] == -1 && cap[tep][i] > f[tep][i])
			{
				level[i] = level[tep] + 1;
				queue[tail++] = i;
			}
		}
	}
	return level[sink] != -1;
}
inline int dinic(){
	int cur,k,m,tail,maxflow = 0, *stack = q;
	while(dinic_bfs()){
		tail = 0;
		stack[tail++] = src;
		while(tail){
			cur = stack[tail-1];
			if(cur == sink){
				m = INF;
				for(int i = 1;i < tail; ++i){
					if(m > cap[stack[i-1]][stack[i]]-f[stack[i-1]][stack[i]]){
						m = cap[stack[i-1]][stack[i]]-f[stack[i-1]][stack[i]];
						k = i;
					}
				}
				maxflow += m;
				for(int i = 1;i < tail; ++i){
					f[stack[i-1]][stack[i]] += m;
					f[stack[i]][stack[i-1]] -= m;
				}
				tail = k;
			}
			else{
				int i;
				for(i = 1;i <= n; ++i){
					if(level[i] == level[cur] + 1 && cap[cur][i] > f[cur][i]){
						stack[tail++] = i;
						break;
					}
				}
				if(i == n+1){
					level[cur] = -1;
					--tail;
				}
			}
		}
	}
	return maxflow;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k;
		scanf("%d%d%d%d",&n,&m,&src,&sink);
		memset(cap,0,sizeof(cap));
		memset(f,0,sizeof(f));
		for(int i = 1;i <= n; ++i){
			scanf("%d",&k);
			cap[2*i-1][2*i] = k;         // 将一个点拆为两个点，容量为点的容量
			cap[2*i][2*i-1] = k;
		}
		while(m--){
			int u,v;
			scanf("%d%d",&u,&v);
			cap[2*u][2*v-1] = INF;
			cap[2*v][2*u-1] = INF;
		}
		n = 2*n; src = 2*src; sink = 2*sink - 1;
		int ans = dinic();
		//if(ans > num || sink+1 == src)//如果最大流大于警察数或者源点汇点是一个点
		//	printf("NO\n");
		//else printf("YES\n");
		printf("%d\n",ans);
	}
}
