#include<cstdio>
#include<cstring>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 10008

vector<int>ans;
map<string,int>mp;
char rela[MAX*10][50];
struct Edge{
	int v, next,id;
	Edge(){}
	Edge(int a, int b,int c):v(a), next(b),id(c){}	
}edge[200080];

int size,cnt, head[MAX];
inline void initg( )
{
	mp.clear();
	ans.clear();
	size = 0;
	cnt=1;
	memset( head, -1, sizeof( head ) );
}

inline void add_edge( int u, int v,int id )
{
	edge[size] = Edge( v, head[u],id );
	head[u] = size++;
	edge[size] = Edge( u, head[v],id );
	head[v] = size++;
}

int dep[MAX], low[MAX], root;
char col[MAX];


void dfs(int u, int father, int depth){
   int i, v, tot = 0;
   col[u] = 1; dep[u] = low[u] = depth;
	for( i = head[u]; i != -1; i = edge[i].next )
	{
	      v = edge[i].v;
	      if(v != father && col[v] == 1)
	      {
	         if( dep[v] < low[u] )
	          low[u] = dep[v];
	      }
	      else if(col[v] == 0){
	         dfs(v, u, depth + 1);
	         tot++;
	         if( low[v] < low[u] )
	          low[u] = low[v];
	         if(low[v] > dep[u])
	         	ans.push_back(edge[i].id);
	      }
	   }
	   col[u] = 2;
}
int main(){
	int T,n,m;
	char a[20],b[20];
	scanf("%d",&T);
   while(T--){
	  scanf("%d%d",&n,&m);
	  getchar();
      initg();
      for(int i = 0; i < m; ++i){
		 gets(rela[i]);
         sscanf(rela[i],"%s%s", a, b);
         if(mp.find(a)==mp.end())
         	mp[a]=cnt++;
          if(mp.find(b)==mp.end())
          	mp[b]=cnt++;
         add_edge( mp[a], mp[b] ,i);
      }
      if(cnt<n+1)
      {
			printf("0\n");
			continue;
		}
      memset(col, 0, sizeof(col));
      root = 1;
      dfs(1, 0, 1);
      printf("%d\n",ans.size());
      sort(ans.begin(),ans.end());
      for(int i = 0; i <ans.size(); ++i)
         printf("%s\n", rela[ans[i]]);
   }
}

