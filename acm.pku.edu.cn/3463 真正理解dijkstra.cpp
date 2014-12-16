/*
本题若开始直接在Dijkstra中加入针对加1的递推式, 必须在Dijkstra的过程中加入DFS, 很繁琐. 改换求次短路, 然后判断次短路是否比最短路长1.

求次短路需要深刻理解Dijkstra的定标技术, 思想就是每次都将某个状态的标记(即长度)永久固定,因此做2*n次,只有理解了这个，才能明白为什么Dijkstra要做2*n的循环——因为次短路同样可以在定标的过程中确定下来,类似最短路，次短路的更新有两种方式：1、最短路变化，淘汰的值；2、父辈结点次短路的松弛更新；因为最短路的值小于次短路的值，所以，1类更新必然在2类更新之前完成，所以保证了定标确定次短路结点的正确性。

普通的Dijkstra的状态是一维的, 即顶点编号占一维, 每次确定一个顶点编号下的最短路. 现在将状态扩展到二维, 第一维仍然是顶点编号, 第二维的长度只有2, 用于分别记录最短路和次短路, 直观点说就是开一个二维数组, 第一维是顶点数, 第二维0号位置放最短路, 1号位置放次短路. 这样的二维数组有两个, 一个记录距离, 一个用于计数. 同样的, 用于记录状态的数组变成了二维, 放进堆中的状态也必须是"二维"的, 这里的"二维"并不是要你开个二维数组, 而是需要在放入堆中的结构体里多加一个标记变量, 用于标识到底是最短路还是次短路, 当然, 用于标记已经确定最短路的点的closed表同样要变成二维的, 循环结束条件必须是堆为空, 因为要计数, 就必须遍历所有情况.

具体在做状态转移的时候, 拿到当前状态, 扩展下一状态, 设当前状态长度为d, 下一状态最短路和次短路状态分别是d0和d1, 则:

d小于d0, 则d1=d0,d0=d, 计数都重置为所赋的值对应的计数.
d等于d0, 则累加最短路计数.
d小于d1, 则d1=d, 重置次短路计数为所赋的值对应的计数.
d等于d1, 则累加次短路计数.
*/
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
            else if (now_cost == dist[now_vex][0])
            {
                cnt[now_vex][0] += cnt[u][temp];
                //printf("cnt[now_vex][0] == %d\n", cnt[now_vex][1]);
            }
            else if (now_cost < dist[now_vex][1])
            {
                dist[now_vex][1] = now_cost;
                cnt[now_vex][1] = cnt[u][temp];
                node.vex = now_vex;
                node.fg = 1;
                heap.push(node);
                //printf("cnt[now_vex][1] == %d\n", cnt[now_vex][1]);
            }
            else if (now_cost == dist[now_vex][1])
            {
                cnt[now_vex][1] += cnt[u][temp];
                //printf("cnt[now_vex][1] == %d\n", cnt[now_vex][1]);
            }
        }
    }
}
int main()
{
    int x;
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
        scanf("%d %d", &s, &t);

        dijkstra();
        int ans = cnt[t][0];
        if (dist[t][0] == dist[t][1] - 1)
            ans += cnt[t][1];
        printf("%d\n", ans);

    }
}

