#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

const int MAXN = 50001;
const int MAXM = 100010;
const unsigned long long INF = (unsigned long long)(1) <<63;

struct edge_T
{
    int v;
    unsigned long long w;
    edge_T *next;
}*adj[MAXN], memo[MAXM];

struct node_T
{
    int v;
    unsigned long long len;
    bool operator < (const node_T &nod)const
    {
        return len > nod.len;
    }
};

int mSet;
unsigned long long weight[MAXN];

void addEdge(int u, int v, unsigned long long w)
{
    edge_T *ptr = &memo[mSet ++];
    ptr -> v = v;
    ptr -> w = w;
    ptr -> next = adj[u];
    adj[u] = ptr;
}
unsigned long long dijkstra(int s, int n)
{
    priority_queue <node_T> Q;
    node_T cur;
    cur.v = s;
    cur.len = 0;
    Q.push(cur);
    unsigned long long dist[MAXN];
    for(int i = 1; i <= n; i ++) dist[i] = INF;
    dist[s] = 0;
    while(! Q.empty())
    {
        int v = Q.top().v;
        unsigned long long len = Q.top().len;
        Q.pop();
        if(len != dist[v])
            continue; //不是当前局部最优解，无须更新
        for(edge_T *ptr = adj[v]; ptr; ptr = ptr -> next)
        {
            int u = ptr -> v;
            unsigned long long w = ptr -> w;
            if(dist[v] + w < dist[u])
            {
                dist[u] = dist[v] + w;
                cur.v = u;
                cur.len = dist[u];
                Q.push(cur);
            }
        }
    }
    for(int i = 1; i <= n; i ++)
    {
        if(dist[i] == INF)
            return INF;
    }

    unsigned long long minimumCost = 0;
    for(int i = 1; i <= n; i ++)
        minimumCost += dist[i] * weight[i];

    return minimumCost;
}
int main()
{
    int casn;
    scanf("%d", &casn);
    while(casn--)
    {
        int i, vn, en;
        scanf("%d %d", &vn, &en);
        for(i = 1; i <= vn; i ++)
        {
            scanf("%I64d", &weight[i]);
            adj[i] = NULL;
        }
        mSet = 0;
        int u, v;
        unsigned long long w;
        for(i = 1; i <= en; i ++)
        {
            scanf("%d %d %I64d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        unsigned long long minimumCost = dijkstra(1, vn);

        if(minimumCost == INF)
            printf("No Answer\n");
        else
            printf("%I64u\n", minimumCost);
    }
    return(0);
}
