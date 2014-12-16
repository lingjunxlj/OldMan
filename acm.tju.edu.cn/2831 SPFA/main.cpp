#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int inf = 0x7ffff;
const int N = 501;
int nums[N], d[N];
bool IsQ[N];
struct
{
    int x, w;
    int next;

} Node[N*N];

int Adj[N][2], curnt;

void add(int u, int v, int w)
{
     Node[curnt].x = v;
     Node[curnt].w = w;
     Node[curnt].next = -1;

     if(Adj[u][0] == -1)
        Adj[u][0] = curnt;
     else
        Node[Adj[u][1]].next = curnt;

     Adj[u][1] = curnt ;
     curnt += 1;
}
bool spfa(int n,int s)
{
     for(int i = 0; i <= n;i++)
     {
         d[i] = inf;
         IsQ[i] = false;
         nums[i] = 0;
     }

     queue <int> Q;

     Q.push(s);
     d[s] = 0;
     IsQ[s] = true;
     nums[s] += 1;

     while(!Q.empty())
     {
         int u = Q.front();
         Q.pop();

         IsQ[u] = false;
         for(int i = Adj[u][0]; i != -1; i = Node[i].next)
         {
             int v = Node[i].x;

             if(d[v]-d[u] > Node[i].w)
             {
                 d[v] = d[u] + Node[i].w;

                 if(IsQ[v] == false)
                 {

                     if(nums[v]>n+1)
                        return true;

                     IsQ[v] = true;
                     nums[v] += 1;
                     Q.push(v);
                 }
             }
         }
     }
     return false;
}
int main()
{
    int n, m;
    int t, wl;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &wl);

        for(int i = 0; i <= n; i++)
        Adj[i][1] = Adj[i][0] = -1;

        curnt = 0;
        int a, b, c;

        for(int i = 1; i <= m; i++)
        {

            scanf("%d %d %d", &a, &b, &c);
            add(a, b, c);
            add(b, a, c);
        }
        for(int i = 1; i <= wl; i++)
        {

            scanf("%d %d %d", &a, &b, &c);
            add(a, b, -c);
        }

        for(int i = 1; i <= n; i++)
        add(0, i, 0);

        if(spfa(n,0))
            puts("YES");

        else
            puts("NO");
    }
    return 0;
}
