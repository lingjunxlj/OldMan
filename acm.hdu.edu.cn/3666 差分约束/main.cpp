#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m, l, u;
int MATRIX[810][810], edgenum[810];
bool flag[810], ins[810];
double dist[810];
struct Edge
{
    int v;
    double w;
}map[800][2000];

void addE(int a,int b,double c)
{
    map[a][edgenum[a]].v = b;
    map[a][edgenum[a]].w = c;
    edgenum[a]++;
    return;
}
bool SPFA(int v)
{
    bool res = false;
    if (ins[v])
        return true;
    ins[v] = true;
    flag[v] = true;
    for (int i = 0; i < edgenum[v]; ++i)
    {
        if (dist[map[v][i].v] < dist[v] + map[v][i].w)
        {
            dist[map[v][i].v] = dist[v] + map[v][i].w;
            if (SPFA(map[v][i].v))
            {
                res = true;
                break;
            }
        }
    }

    ins[v] = false;
    return res;
}
bool cycle()
{
    memset(flag, 0, sizeof(flag));
    memset(ins, 0, sizeof(ins));
    for (int i = 0; i < n + m; ++i)
        dist[i] = 0;

    for (int i = 0; i < n + m; ++i)
        if (!flag[i])
            if (SPFA(i))
                return false;

    return true;
}
int main()
{
    while (scanf("%d%d%d%d", &n,&m,&l,&u) != EOF)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                scanf("%d", &MATRIX[i][j]);
        memset(edgenum, 0, sizeof(edgenum));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                addE(i, j + n, log((double)MATRIX[i][j]) - log((double)u));
                addE(j + n, i, log((double)l) - log((double)MATRIX[i][j]));
            }
        if (cycle())
            printf("YES\n");
        else
            printf("NO\n");

    }
}

/*
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <fstream>
#include <numeric>
#include <queue>
#include <cstring>
#include <string>
#include <cassert>
#include <map>
#include <cmath>

using namespace std;

struct Edge {
    int v;
    double w;
};

Edge graph[800][2000];
int matrix[400][400];
int n, m, l, u;
int nv;
bool vis[800];
double dis[800];
bool ins[800];
int nEdge[800];

inline void addEdge(int s, int e, double w) {
    graph[s][nEdge[s]].v = e;
    graph[s][nEdge[s]++].w = w;

    return;
}

bool spfa(int v) {
    bool res = false;

    if (ins[v]) {
        return true;
    }

    ins[v] = true;
    vis[v] = true;
    for (int i = 0; i != nEdge[v]; ++i) {
        if (dis[graph[v][i].v] < dis[v] + graph[v][i].w) {
            dis[graph[v][i].v] = dis[v] + graph[v][i].w;

            if (spfa(graph[v][i].v)) {
                res = true;
                break;
            }
        }
    }

    ins[v] = false;
    return res;
}

bool noCycle() {
    memset(vis, 0, sizeof(vis));
    memset(ins, 0, sizeof(ins));
    for (int i = 0; i != nv; ++i) {
        dis[i] = 0;
    }

    for (int i = 0; i != nv; ++i) {
        if (!vis[i]) {
            if (spfa(i)) {
                return false;
            }
        }
    }

    return true;
}

void solveProb() {
    double lgl = log(l), lgu = log(u);

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }

    nv = n + m;

    for (int i = 0; i != n; ++i) {
        for (int j = 0; j != m; ++j) {
            addEdge(i, j + n, log(matrix[i][j]) - lgu);
            addEdge(j + n, i, lgl - log(matrix[i][j]));
        }
    }

    if (noCycle()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    for(int i = 0; i < n; i++)
            printf("%lf ",dis[i]);
        printf("\n");

        for(int j = n; j < n + m; j++)
            printf("%lf ",dis[j]);
        printf("\n");
    return;
}

int main() {

    while (scanf("%d%d%d%d", &n, &m, &l, &u) != EOF) {
        memset(nEdge, 0, sizeof(nEdge));
        solveProb();
    }

    return 0;
}
*/
