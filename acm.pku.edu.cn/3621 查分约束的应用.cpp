#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cctype>
#include <assert.h>
using namespace std;
int getint() //这个getchar的输入对大数据量输入非常有用，甚至可以挽救效率不高的算法
{
    int ret = 0;
    char tmp;
    while (!isdigit(tmp = getchar()));
    do {
        ret = (ret << 3)+(ret << 1) + tmp - '0';
    } while (isdigit(tmp = getchar()));
    return ret;
}

const int MAXN = 5010;
struct Node
{
    int vex, cost;
}node;

vector <Node> g[MAXN];
double fun[MAXN];
bool flag[MAXN];
double dist[MAXN];
int L, P, visit[MAXN];

int SPFA(double val)
{
    queue <int> Q;
    for(int i = 0; i <= L; i++)
    {
        dist[i] = 0xfff;
        flag[i] = 0;
        visit[i] = 0;
    }

    dist[0] = 0;
    flag[0] = 1;
    Q.push(0);

    while(!Q.empty())
    {
        int u = Q.front();
        //printf("u == %d\n", u);
        Q.pop();
        flag[u] = 0;

        for (int i = 0; i < g[u].size(); i++)
        {
            if (dist[g[u][i].vex] > dist[u] + val * g[u][i].cost - fun[g[u][i].vex])
            {
                dist[g[u][i].vex] = dist[u] + val * g[u][i].cost - fun[g[u][i].vex];
                if (!flag[g[u][i].vex])
                {
                    Q.push(g[u][i].vex);
                    flag[g[u][i].vex] = 1;
                    visit[g[u][i].vex]++;
                    //printf("visit[g[u][i].vex] == %d\n", visit[g[u][i].vex]);

                    if (visit[g[u][i].vex] >= L) //有负环
                        return 1;
                }
            }
        }
    }
    return 0; // 无负环
}
double solution()
{
    double Max;
    double r = 1008*1008*1008, l = 0;
    while(l <= r)
    {
        double mid = (r + l) / 2;
        //printf("mid == %lf\n", mid);
        if (SPFA(mid/1000))
        {
            l = mid + 1;
            Max = mid;
        }
        else
            r = mid - 1;
    }
    return Max;
}
int main()
{

    while(scanf("%d %d", &L, &P) != EOF)
    {
        for (int i = 0; i < L; i++)
        {
            scanf("%lf", &fun[i]);
            g[i].clear();
        }
        for (int i = 0; i < P; i++)
        {
            int a, b;
            scanf("%d %d %d", &a, &b, &node.cost);
            a--; b--;
            node.vex = b;
            g[a].push_back(node);
        }
        double ans = solution();

        if(((int)ans % 10) > 4)
            ans = ans + 10 - (int)ans % 10;
        printf("%.2lf\n",ans / 1000.0);

    }
}
