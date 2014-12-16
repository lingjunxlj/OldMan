#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
const int Maxver = 5005;
struct node
{
       int e,next;
}list[3][7*Maxver];

vector<int>l1[Maxver];
int n,ver,cnt,Maxh,vis[Maxver],ret[Maxver],stck[Maxver];
int head[3][Maxver];
int aadd[Maxver];

void add_edge(int s,int e,int d,int top)
{
       list[d][top].e = e;
       list[d][top].next = head[d][s];
       head[d][s] = top;
}
void DFS(int t)
{
       int i;
       vis[t] = 1;
       for(i = head[1][t]; i != -1; i = list[1][i].next)
       {
              if(!vis[list[1][i].e])
                     DFS(list[1][i].e);
       }
       stck[cnt++] = t;
}
void dfs(int t)
{
       int i;
       vis[t] = 1;
       for(i = head[0][t]; i != -1; i = list[0][i].next)
       {
              if(!vis[list[0][i].e])
                     dfs(list[0][i].e);
       }
       ret[t] = ver;
}
void DFS_high(int root,int h)
{
       int i;
       if(h > Maxh)
              Maxh = h;
        if (aadd[root])
            return;
        aadd[root] = 1;


       //for(i = 0; i < l1[root].size(); i++)
       {
           if (l1[root].size())
           {
                printf("root == %d\n", root);
                printf("l1[%d][1] == %d\n",root, l1[root][1]);
                DFS_high(l1[root][i],h+1);
                DFS_high
           }


       }

}

void solve()
{
       int i,j,sum,cur,root,in[Maxver];
       cnt = 0;
       memset(vis,0,sizeof(vis));
       for(i = 1; i <= n; i++)
              l1[i].clear();
       for(i = 1; i <= n; i++)
       {
              if(!vis[i])
                     DFS(i);
       }
       ver = 0;
       memset(vis,0,sizeof(vis));
       for(i = n-1; i >= 0; i--)
       {
              cur = stck[i];
              if(!vis[cur])
              {
                     ++ver;
                     dfs(cur);
              }
       }
       memset(in,0,sizeof(in));
       memset(aadd, 0, sizeof(aadd));
       for(i = 1; i <= n; i++)
       {
              for(j = head[0][i]; j != -1; j = list[0][j].next)
              {
                     cur = ret[list[0][j].e];
                     if(ret[i] != cur)
                     {
                            in[cur]++;
                            l1[ret[i]].push_back(cur);
                     }
              }
       }
       sum = 0;
       for(i = 1; i <= ver; i++)
       {
              if(!aadd[i])
              {
                  sum++;
                  DFS_high(i, 0);

              }


       }
       printf("%d\n", sum);


}

int main()
{
       int T,i,m,s,e,top;
       scanf("%d",&T);
       while(T--)
       {
              top = 0;
              memset(head,-1,sizeof(head));
              scanf("%d%d",&n,&m);
              for(i = 0; i < m; i++)
              {
                     scanf("%d%d",&s,&e);
                     add_edge(s,e,0,top);
                     add_edge(e,s,1,top);
                     top++;
              }
              solve();
       }
       return 0;
}
