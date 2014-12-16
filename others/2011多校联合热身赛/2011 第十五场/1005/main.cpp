
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;
const int MAXN = 1001;
const int inf = 1000000;


int dist[MAXN][2], cnt[MAXN][2];
bool flag[MAXN][2];
int s, t, m, n;

struct Node
{
    int vex;
    int fg;
}node;

struct Point
{
    int vex;
    int cost;
}point;

vector <Point> map[MAXN];
priority_queue <Node> heap;
bool operator < (Node a, Node b)
{
    return dist[a.vex][a.fg] > dist[b.vex][b.fg];
}

void dijkstra()
{
    int u, temp, now_vex, now_cost;
    memset(flag, 0, sizeof(flag));
    //memset(dist, inf, sizeof(dist));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
        dist[i][0] = dist[i][1] = inf;

    node.vex = s;
    node.fg = 0;
    heap.push(node);
    //printf("s == %d\n", s);
    dist[s][0] = 0;
    cnt[s][0] = 1;

    while(!heap.empty())
    {
        node = heap.top();
        heap.pop();


        u = node.vex;
        temp = node.fg;

        if (flag[u][temp])
            continue;
        flag[u][temp] = 1;

        for (int i = 0; i < map[u].size(); i++)
        {

            point = map[u][i];

            now_vex = point.vex;
            now_cost = point.cost + dist[u][temp];
            if (now_cost < dist[now_vex][0])
            {
                if (dist[now_vex][0] != inf)
                {
                    dist[now_vex][1] = dist[now_vex][0];
                    cnt[now_vex][1] = cnt[now_vex][0];
                    node.vex = now_vex;
                    node.fg = 1;
                    heap.push(node);
                    //printf("cnt[now_vex][1] == %d\n", cnt[now_vex][1]);
                }
                dist[now_vex][0] = now_cost;
                cnt[now_vex][0] = cnt[u][temp];
                node.vex = now_vex;
                node.fg = 0;
                heap.push(node);
                //printf("cnt[now_vex][0] == %d\n", cnt[now_vex][1]);
            }

        }
    }
}
int main()
{
    int x, cnt1;
    scanf("%d", &x);
    while(x--)
    {
        scanf("%d %d", &n, &m);

        for (int i = 1; i <= n; i++)
        {
            map[i].clear();

        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d %d", &a, &b, &point.cost);
            point.vex = b;
            map[a].push_back(point);


        }

        s = 1, t = n;

        dijkstra();
        int Max = dist[t][0];
        int ans = dist[t][0];
        //printf("Max = %d\n", Max);
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < map[i].size(); j++)
            {

                int a, b, c;
                a = i;
                b = map[i][j].vex;
                c = map[i][j].cost;
                map[i].erase(map[i].begin() + j);
                //printf("a = %d b = %d\n", i, map[i][j].vex);
                dijkstra();
                if (dist[t][0] > Max && dist[t][0] != inf)
                    Max = dist[t][0];
                point.cost = c;
                point.vex = b;
                map[a].push_back(point);
                //printf("Max = %d\n", Max);
            }
        //int ans = cnt[t][0];

        if (Max == ans)
            printf("-1\n");
        else
            printf("%d\n", Max);

    }
}

