#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 311;
const int INF = 0x3f;

typedef struct c
{
	int from;
	int end;
	int w;
}SD;

SD temp;
bool operator <(SD x,SD y)
{
		return x.w>y.w;
}
priority_queue<SD> q;



int m, n;
int map[MAX][MAX];
int Queue[2][MAX];
vector <int> grap[2][MAX];
int dp[MAX][MAX];
int head[2], dist[MAX], flag[MAX];
struct node
{
    int val;
    int pos;
}num[MAX];

int min(int a, int b)
{
    return a<b? a : b;
}
int max(int a, int b)
{
    return a>b? a : b;
}
bool cmp(node a, node b)
{
    return a.val < b.val;
}
void dij(int st, int id)
{
    int u, Min;
    memset(dist, 0x3f, sizeof(dist));
    memset(flag, 0, sizeof(flag));
    /////////////////////////////////////heap 优化
    //memset(visited,false,sizeof(visited));
    /*
	dist[st]=0;
	flag[st]=true;
	temp.from=st;
	for(int i=1;i<=p;++i)//从源点第一次松弛
	{
		if(!flag[i])
		{
			temp.end=i;
			temp.w=map[st][i];
			q.push(temp);
		}
	}
	SD t;
	priority_queue<SD> qq;
	for(int i=2;i<=n;++i)
	{
		while(!q.empty())
		{
			t=q.top();
			if(!flag[t.end])
                qq.push(t);
			q.pop();
		}
		t = qq.top();
		qq.pop();
		dist[t.end] = t.w;
		flag[t.end]=true;

		SD t1;
		while(!qq.empty())
		{
			t1=qq.top();
			qq.pop();
			if(map[t.end][t1.end]+t.w<t1.w)
			{
				t1.w = map[t.end][t1.end]+t.w;
			}
			q.push(t1);
		}
	}
	*/

    ////////////////////////////////////////普通
    //for (int i = 1; i <= n; i++)
        //dist[i] = map[st][i];
    dist[st] = 0;
    for (int i = 1; i <= n; i++)
    {
        u = -1;
        Min = 0x3ffff;
        for (int j = 1; j <= n; j++)
        {
            if (Min > dist[j] && !flag[j])
            {
                u = j;
                Min = dist[j];
            }
        }
        if(u == -1)
            break;
        flag[u] = 1;

        for (int j = 1; j <= n; j++)
        {
            if (!flag[j] && dist[j] > dist[u] + map[u][j])
                dist[j] = dist[u] + map[u][j];
        }
    }
    //for (int i = 1; i <= n; i++)
        //printf("%d\n", dist[i]);
    //printf("2\n");
    memset(flag, 0, sizeof(flag));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && dist[j] == dist[i] + map[i][j])
            {
                flag[i] = flag[j] = 1;
                grap[id][j].push_back(i);
            }
    for (int i = 1; i <= n; i++)
    {
        if (flag[i])
        {
            num[head[id]].val = dist[i];
            num[head[id]].pos = i;
            head[id]++;
        }
    }
    //printf("head[%d] = %d\n", id, head[id]);
    sort(num, num + head[id], cmp);
    for (int i = 0; i < head[id]; i++)
    {
        Queue[id][i] = num[i].pos;
        //printf("Queue[%d][%d] == %d\n", id, i, num[i].pos);
    }
    return;
}
int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        SD t;
        memset(map, 0x3f, sizeof(map));
        memset(head, 0, sizeof(head));
        for (int i = 1; i <= n; i++)
            map[i][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            grap[0][i].clear();
            grap[1][i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            map[a][b] = map[b][a] = min(map[a][b], c);
            //printf("map == %d\n", map[a][b]);

            //scanf("%d %d %d", &t.from, &t.end, &t.w);
            //map[t.from][t.end] = map[t.end][t.from] = min(t.w, map[t.from][t.end]);
        }
        int st1, end1, st2, end2;
        scanf("%d %d %d %d", &st1, &end1, &st2, &end2);
        //printf("1\n");
        dij(st1, 0);
        dij(st2, 1);
        //printf("end\n");
        memset(dp, 0, sizeof(dp));
        int pre_i, pre_j;
        int temp_a, temp_b;
        for (int i = 0; i < head[0]; i++)
            for (int j = 0; j < head[1]; j++)
            {
                temp_a = grap[0][Queue[0][i]].size();
                temp_b = grap[1][Queue[1][j]].size();
                if (temp_a != 0 && temp_b != 0)
                {
                    for (int i2 = 0; i2 < temp_a; i2++)
                    {
                        pre_i = grap[0][Queue[0][i]][i2];
                        for (int j2 = 0; j2 < temp_b; j2++)
                        {
                            pre_j = grap[1][Queue[1][j]][j2];
                            if (Queue[0][i] == Queue[1][j])
                                dp[Queue[0][i]][Queue[1][j]] = max(dp[Queue[0][i]][Queue[1][j]], dp[pre_i][pre_j] + 1);
                            else
                            {
                                dp[Queue[0][i]][Queue[1][j]] = max(dp[Queue[0][i]][Queue[1][j]], dp[Queue[0][i]][pre_j]);
                                dp[Queue[0][i]][Queue[1][j]] = max(dp[Queue[0][i]][Queue[1][j]], dp[pre_i][Queue[1][j]]);
                            }
                        }
                    }
                }
                else
                {
                    if (Queue[0][i] == Queue[1][j])
                        dp[Queue[0][i]][Queue[1][j]] = 1;

                }
            }
            printf("%d\n", dp[end1][end2]);
    }
}
