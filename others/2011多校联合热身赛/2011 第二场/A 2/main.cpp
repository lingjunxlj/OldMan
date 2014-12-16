#include <cstdio>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstring>
using namespace std;
const int N = 100005;
const int Inf = 0x7fffffff;
struct edge{
   int nxt,to,w;
} e[N*2];
int a[N][2],d[N],cnt;
int b[2*N],ix[2*N],p[N],ps[N],lb;
int dp[2*N][18],id[2*N][18],c[2*N];
int deg[N*2], sta[N*2];
int getn(){
	char ch;
	int res=0;
	for(ch=getchar();'0'<=ch&&ch<='9';ch=getchar())
		res=res*10+ch-'0';
	return res;
}
void init(int n)
{
    for(int i=1;i<=n;++i)
    a[i][0]=a[i][1]=-1,
    d[i]=Inf;
    for(int i=1,nn=2*n;i<=nn;++i)c[i]=0;
    cnt = 1;
}
void insert_edge(int x,int y,int w)
{
    e[cnt].nxt = -1;
    e[cnt].to = y;
    e[cnt].w = w;
    if(a[x][0]==-1)a[x][0]=cnt;
    else e[a[x][1]].nxt=cnt;
    a[x][1]=cnt++;
}
// Ê÷×´Êý×é
int lowbit(int x){ return x&(-x);}
void update(int i,int n,int k)
{
    for(int j=i;j<=n;j+=lowbit(j))c[j]+=k;
}
int sum(int i)
{
    int ret = 0;
    while(i>0)ret+=c[i],i-=lowbit(i);
    return ret;
}
// DFS
void dfs(int u,int n)
{
    b[++lb] = d[u];
    ix[lb] = u;
    p[u] = lb;
    for(int i=a[u][0];i!=-1;i=e[i].nxt)
    {
        bool ck = false;
        int v = e[i].to;
        if(d[v]==Inf)
        {
            d[v] = d[u]+1;
            ck = true;
            dfs(v,n);
            update(p[v],n,e[i].w);
            update(ps[v]+1,n,-e[i].w);
        }
        if(ck)
        {
            b[++lb] = d[u];
            ix[lb] = u;
        }
    }
    ps[u] = lb;
}

// RMQ
void initRMQ(int n)
{
    for(int i=1;i<=n;++i)dp[i][0]=b[i],id[i][0]=i;
    for(int j=1,s=1;s<=n;s=(1<<j++))
    for(int i=1,k=2*s-1;i+k<=n;++i)
    if(dp[i][j-1]<dp[i+s][j-1])
    {
        dp[i][j]=dp[i][j-1];
        id[i][j]=id[i][j-1];
    }else
    {
        dp[i][j]=dp[i+s][j-1];
        id[i][j]=id[i+s][j-1];
    }
}
int queryRMQ(int u,int v)
{
    int k = 1;
    while((1<<k)<=(v-u+1))++k;
    --k;
    if(dp[u][k]<dp[v-(1<<k)+1][k])return ix[id[u][k]];
    return ix[id[v-(1<<k)+1][k]];
}
void build(int n)
{
    lb = 0; d[1]=0;
    dfs(1,2*n-1);
    initRMQ(lb);
}
int queryAns(int u,int v)
{
    int x=p[u],y=p[v];
    if(x>y) x^=y^=x^=y;
    int pp = queryRMQ(x,y);
    return sum(x)+sum(y)-2*sum(p[pp]);
}
int main()
{
    int n,q,s;
    while(scanf("%d\n",&n), n)
    {
        init(n);
        //memset(deg, 0, sizeof(deg));
        //memset(sta, 0, sizeof(sta));
        for(int i=1;i<n;++i)
        {
            int x,y,w;
            x = getn();
            y = getn();
            w = getn();
            //scanf("%d%d%d",&x,&y,&w);
            deg[x]++; deg[y]++;
            insert_edge(x,y,w);
            insert_edge(y,x,w);
        }
        build(n);

        int p=0;
		for(int i = 1; i <= n; i++)
		{
			if(deg[i] == 1)
			    sta[++p] = i;
		}
        s = sta[1];
        //cout<<sta[1]<<endl;
        int Min, Min2 = 99999999;
        for (int i = 1; i < p; i++)
        {
            Min = 99999999;
            for (int j = i+1; j < p; j++)
            {
                if(queryAns(sta[i],sta[j]) < Min)
                    Min = queryAns(sta[i],sta[j]);
                //printf("%d\n",Min);
            }
            if (Min < Min2)
                Min2 = Min;
        }

        printf("%d\n", Min2);
    }
    return 0;
}
