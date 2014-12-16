#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int MAXN = 301;
int a[5][2] =
{
    { 0,  0},
    {-1,  0},
    { 0,  1},
    { 1,  0},
    { 0, -1}
};
bool map[MAXN][MAXN];
int dist[MAXN][MAXN];
int turn[MAXN][MAXN];
bool mk[MAXN][MAXN];
int q, w;
struct point
{
    int i;
    int j;
    int dist;
    bool operator <(const point &it)const
    { return dist > it.dist;}
};
int bfs (point u, point s)
{
        priority_queue<point>qi;
        int i, j, k, min;
        point temp;
        memset(mk, 0, sizeof(mk));

        for(i = 0; i <= q + 1; i++)
            for(j = 0; j <= w + 1; j++)
                dist[i][j] = 0x7ffff;


        i = u.i;
        j = u.j;

        turn[i][j] = 0;
        dist[i][j] = 0;

        mk[i][j] = 1;

        for(k = 1; k <= 4; k++)
        {
            i = u.i + a[k][0];
            j = u.j + a[k][1];
            if(!map[i][j])
            {
                turn[i][j] = k;

                if(k == 1)
                dist[i][j] = 1;
                else if(k == 3)
                dist[i][j] = 3;
                else dist[i][j] = 2;

                temp.i = i;
                temp.j = j;
                temp.dist = dist[i][j];
                qi.push(temp);
            }
        }

        while( !qi.empty() )
        {
            u = qi.top();
            qi.pop();

            if(u.i == s.i && u.j ==s.j)
            return dist[s.i][s.j];

            if(map[u.i][u.j])
            continue;

            mk[u.i][u.j] = 1;

            for(k = 1; k <= 4; k++)
            {
                i = u.i + a[k][0];
                j = u.j + a[k][1];
                if(i >= 0 && i <= q + 1 && j >= 0 && j <= w + 1 && !mk[i][j] )
                {
                    if(turn[u.i][u.j] == k)
                    min = dist[u.i][u.j] + 1;
                    else min = dist[u.i][u.j] + 2;

                    if(min < dist[i][j])
                    {
                        dist[i][j] = min;
                        turn[i][j] = k;
                        temp.i = i;
                        temp.j = j;
                        temp.dist = min;
                        qi.push(temp);
                    }
                }
            }
        }
        return -1;
}

int main()
{
    int i, j, k = 1, ans, t;
    char c;
    point begin, end;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &q, &w);
        {
            for(i = 0; i <= q + 1; i++)
                for(j = 0; j <= w + 1; j++)
                    map[i][j] = 1;

            for(i = 1; i <= q; i++)
            {
                getchar();
                for(j = 1; j <= w; j++)
                {
                    scanf("%c", &c);
                    if(c == '.')
                    map[i][j] = 0;
                    else if(c == 'S')
                    {
                        begin.i = i;
                        begin.j = j;
                        map[i][j] = 0;
                    }
                    else if(c == 'T')
                    {
                        end.i = i;
                        end.j = j;
                        map[i][j] = 0;
                    }
                }
            }
            ans = bfs(begin, end);
            printf("%d\n", ans);
        }
    }
}
