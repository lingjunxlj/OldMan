/*
    每个客户i作为一个节点分别向相应中转站Ai,Bi连有向边，容量INF
    源点s向每个客户连边，容量为收益Ci
    每个中转站向汇点t连有向边，容量为建站花费Xi

    那么答案就是 总收益-最小割（割边总和）
    用户群与必要的中转站是一个闭合图，问题就是选与不选了

    选的话，就是S集合了，不选就是T集合了
    s到T集合、S集合到t都是割边
    选，则需要建站花费，即S集合到t的边
    不选，则损失利益，即s到T集合的边
    要使最大，肯定是割边和最小，就是最小割了
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 55100;
const int INF = 0x7fff;
int min(int a, int b)
{
    return a < b? a:b;
}
struct Edge
{
    int v,cap;
    Edge *next,*pair;
}edge[MAXN*10];
struct Graph
{
    Edge *E[MAXN], *cur[MAXN];
    Edge *pE;
    int dist[MAXN], num[MAXN];
    int n, s, t;
    bool found;
    void init(int nn, int ss, int tt)
    {
        n = nn;
        s = ss;
        t = tt;
        memset(E, 0, sizeof(Edge*) * n);
        pE = edge;
    }
    void add(int u, int v, int cap, Edge *pair)
    {
        pE->v = v;
        pE->cap = cap;
        pE->pair = pair;
        pE->next = E[u];
        E[u] = pE++;
    }
    void add(int u, int v, int cap)
    {
        add(u, v, cap, pE+1);
        add(v, u,0, pE-1);
    }
    int aug(int u,int preCap)
    {
        if(u == t)
        {
            found = true;
            return preCap;
        }
        int leftCap = preCap;
        for(Edge *&it = cur[u]; it; it = it->next)
        {
            if(it -> cap && dist[u] == dist[it->v] + 1)
            {
                int d = aug(it->v, min(it->cap, leftCap));
                leftCap -= d;
                it->cap -= d;
                it->pair->cap += d;
                if(dist[s] == n || leftCap == 0)return preCap-leftCap;
                if(found)break;
            }
        }
        if(!found)
        {
            int minD=n;
            for(Edge *it=E[u];it;it=it->next)
            {
                if(it->cap)
                    minD = min(minD, dist[it->v] + 1);
            }
            if(--num[dist[u]] == 0)
                dist[s] = n;
            else
                num[dist[u] = minD]++;
            cur[u] = E[u];
        }
        return preCap - leftCap;
    }
    int sap()
    {
        memset(dist, 0, sizeof(int)*n);
        memset(num, 0, sizeof(int)*n);
        memmove(cur, E, sizeof(Edge*)*n);
        num[0] = n;
        int flow = 0;
        while(dist[s] < n)
        {
            found = false;
            flow += aug(s,INF);
        }
        return flow;
    }
}graph;

int main()
{
    int n, m, T, x;
    while(~scanf("%d %d", &n, &m))
    {

        int s = 0, t = n + m + 1;
        graph.init(n + m + 2, s, t);

        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            graph.add(m+i, t, x);
        }
        int ans = 0;
        for(int i = 1; i <= m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            ans += c;
            graph.add(s, i, c);
            graph.add(i, m + a, INF);
            graph.add(i, m + b, INF);
        }
        printf("%d\n", ans - graph.sap());
    }
    return 0;
}
