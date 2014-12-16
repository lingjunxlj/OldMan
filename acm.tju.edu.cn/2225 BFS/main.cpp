#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
char maze[101][101][101];
int n;
int tc, tx, ty;
int dir[][2] =
{
     1,  0,
    -1,  0,
     0,  1,
     0, -1
};
struct node
{
    int x;
    int y;
    int c;
    int step;
}t, top;
void Insert(queue<node> &q, node &x)
{
    if(maze[x.c][x.x][x.y] != 'X')
    {
        maze[x.c][x.x][x.y] = 'X';
        q.push(x);
    }
}
void bfs()
{
    int i;
    queue <node> q;
    t.step = 0;
    q.push(t);

    while(!q.empty())
    {
        top = q.front();
        q.pop();

        if(top.x == tx && top.y == ty && top.c == tc)
        {
            printf("%d %d\n", n, top.step);
            return;
        }
        t.step = top.step+1;
        t.c = top.c;

        for(i = 0; i < 4; i++)
        {
            t.x = top.x + dir[i][0];
            t.y = top.y + dir[i][1];

            if( t.x >= 0 && t.x < n && t.y >= 0 && t.y < n )
            Insert(q, t);
                //if(maze[t.c][t.x][t.y] != 'X')
                //{
                    //maze[t.c][t.x][t.y] = 'X';
                    //q.push(t);
               // }
        }
        top.step++;
        if(top.c > 0)
        {
            top.c--;
            //if(maze[top.c][top.x][top.y] != 'X')
            //{
                //maze[top.c][top.x][top.y] = 'X';
                //q.push(t);
            //}
            Insert(q, top);
            top.c++;
        }
        if(top.c < n-1)
        {
            top.c++;
            //if(maze[top.c][top.x][top.y] != 'X')
            //{
                //maze[top.c][top.x][top.y] = 'X';
                //q.push(t);
            //}
            Insert(q, top);
        }
    }
    cout << "NO ROUTE\n";
}
int main()
{
    int i, j, k;
    char str[10];
    while(cin >> str >> n)
    {
        for(k = 0; k < n; k++)
            for(i = 0; i < n; i++)
                for(j = 0; j < n; j++)
                    cin >> maze[k][i][j];
        cin >> t.y >> t.x >> t.c >> ty >> tx >> tc >> str;
        bfs();
    }
}
