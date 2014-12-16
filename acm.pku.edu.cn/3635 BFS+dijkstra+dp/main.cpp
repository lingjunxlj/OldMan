#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1008;
struct Point
{
   int v, dist ;
}point;

struct Node
{
    int city, fuel, cost;
    Node (int a, int b, int c)
    {
        city = a; fuel = b; cost = c;
    }
};

bool operator < (Node a, Node b)
{
    return a.cost > b.cost;
}
priority_queue <Node> heap;
vector <Point> map[MAXN];

int S, T, V, n, m, price[MAXN], dp[MAXN][108];
bool visit[MAXN][108];

int BFS()
{
    int temp_city, temp_fuel, temp_cost;

    while(!heap.empty())
        heap.pop();

    heap.push(Node(S, 0, 0));
    dp[S][0] = 0;

    while(!heap.empty())
    {
        Node tp = heap.top();
        heap.pop();
        temp_city = tp.city;
        temp_fuel = tp.fuel;
        temp_cost = tp.cost;
        //printf("city = %d\nfuel = %d\ncost = %d\n", temp_city, temp_fuel, temp_cost);

        visit[temp_city][temp_fuel] = 1;

        if (temp_city == T)
            return temp_cost;

        if (temp_fuel + 1 <= V && !visit[temp_city][temp_fuel + 1] && dp[temp_city][temp_fuel + 1] > dp[temp_city][temp_fuel] + price[temp_city])
        {
            dp[temp_city][temp_fuel + 1] = dp[temp_city][temp_fuel] + price[temp_city];
            heap.push(Node(temp_city, temp_fuel + 1, dp[temp_city][temp_fuel + 1]));
        }

        for (int i = 0; i < map[temp_city].size(); i++)
        {
            int u = map[temp_city][i].v;
            int now = temp_fuel - map[temp_city][i].dist;
            if (now >= 0 && !visit[u][now] && temp_cost < dp[u][now])
            {
                dp[u][now] = temp_cost;
                //printf("dp[u][now] == %d\n", dp[u][now]);
                heap.push(Node(u, now, dp[u][now]));
            }
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &price[i]);

        for (int i = 0; i < n; i++)
            map[i].clear();

        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d %d", &a, &b, &point.dist);

            point.v = b;
            map[a].push_back(point);

            point.v = a;
            map[b].push_back(point);
        }
        int t;
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d %d %d", &V, &S, &T);

            memset(visit, 0, sizeof(visit));
            for (int i = 0; i < n; i++)
                for (int j = 0; j < 101; j++)
                    dp[i][j] = 9999999999;

            int ans = BFS();
            if (ans == -1)
                printf("impossible\n");
            else
                printf("%d\n", ans);


        }
    }
}
