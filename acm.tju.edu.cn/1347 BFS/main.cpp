#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 60;
struct node
{
    int a;
    int b;
    int c;
    int step;
}start, temp;
int n;
int visit[MAX][MAX][MAX];
char map[MAX][MAX];
int bfs()
{
    int i;
    queue <node> q;
    start. step = 0;
    visit[start.a][start.b][start.c] = 1;

    if (start.a == start.b && start.b == start.c)
    return 0;

    q.push(start);

    while (!q.empty())
    {
        start = q.front();
        q.pop();

        for (i = 1; i <= n; i++)
        {
            if (map[start.a][i] == map[start.b][start.c] && !visit[i][start.b][start.c])
            {
                visit[i][start.b][start.c] = 1;
                temp.step = start.step + 1;

                temp.a = i;
                temp.b = start.b;
                temp.c = start.c;

                if (temp.a == temp.b && temp.b == temp.c)
                return temp.step;

                q.push(temp);
            }

            if (map[start.b][i] == map[start.a][start.c] && !visit[start.a][i][start.c])
            {
                visit[start.a][i][start.c] = 1;
                temp.step = start.step + 1;

                temp.b = i;
                temp.a = start.a;
                temp.c = start.c;

                if (temp.a == temp.b && temp.b == temp.c)
                return temp.step;

                q.push(temp);
            }

            if (map[start.c][i] == map[start.a][start.b] && !visit[start.a][start.b][i])
            {

                visit[start.a][start.b][i] = 1;
                temp.step = start.step + 1;

                temp.c = i;
                temp.b = start.b;
                temp.a = start.a;

                if (temp.a == temp.b && temp.b == temp.c)
                return temp.step;

                q.push(temp);
            }

        }

    }
    return -1;
}
int main()
{
    int i, j, ans;
    while (cin>>n, n)
    {
        memset(visit, 0, sizeof(visit));

        cin>>start.a>>start.b>>start.c;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                cin>>map[i][j];

        ans = bfs();

        if (ans != -1)
        printf("%d\n",ans);
        else
        printf("impossible\n");
    }
}
