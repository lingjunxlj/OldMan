#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
int M, N;
bool Stone[50][50], Flag[50][50][4];
struct Point
{
    int x;
    int y;
    int step;
    int dir;
}st,et,mt,nt;
int dx[4][3]=
{
    -1, -2, -3,
     0,  0,  0,
     1,  2,  3,
     0,  0,  0
};
int dy[4][3]=
{
     0,  0,  0,
     1,  2,  3,
     0,  0,  0,
    -1, -2, -3
};
void BFS()
{
    int i;
    queue<Point>Queue;
    Queue.push(st);
    Flag[st.x][st.y][st.dir] = 1;
    while ( !Queue.empty() )
    {
        mt = Queue.front();
        Queue.pop();
        if(mt.x == et.x && mt.y == et.y)
        {
            printf("%d\n", mt.step);
            return ;
        }
        int step = mt.step;
        int dir = mt.dir;
        nt.step = step + 1;
        nt.dir = dir;
        for(i = 0; i < 3; i++)
        {
            nt.x = mt.x + dx[dir][i];
            nt.y = mt.y + dy[dir][i];

            if(nt.x <= 0||nt.y <= 0||nt.x >= M||nt.y >= N)
            break;

            if(Stone[nt.x][nt.y])
            break;

            if(Flag[nt.x][nt.y][nt.dir])
            continue;

            Flag[nt.x][nt.y][nt.dir] = 1;
            Queue.push(nt);
        }

        mt.step = step + 1;
        mt.dir = dir + 1;
        if(mt.dir > 3)
        mt.dir = 0;
        if(!Flag[mt.x][mt.y][mt.dir])
        {
            Queue.push(mt);
            Flag[mt.x][mt.y][mt.dir] = 1;
        }

        mt.step = step + 1;
        mt.dir = dir - 1;
        if(mt.dir < 0)
        mt.dir = 3;
        if(!Flag[mt.x][mt.y][mt.dir])
        {
            Queue.push(mt);
            Flag[mt.x][mt.y][mt.dir] = 1;
        }
    }
    printf("-1\n");
}
int main()
{
    int temp = 0, i, j;
    char str[10];
    while(scanf("%d %d",&M, &N))
    {
        if (M == 0 && N == 0)
        break;

        for(i = 0; i < M; i++)
            for(j = 0; j < N; j++)
                Stone[i][j] = 0;

        for(i = 0; i < M; i++)
            for(j = 0; j < N; j++)
               {
                   scanf("%d", &temp);
                   if(temp)
                   {
                        Stone[i][j] = 1;
                        Stone[i][j + 1] = 1;
                        Stone[i + 1][j] = 1;
                        Stone[i + 1][j + 1] = 1;
                   }
               }
        scanf("%d %d %d %d %s", &st.x, &st.y, &et.x, &et.y, str);
        if(Stone[et.x][et.y])
        {
            printf("-1\n");
            continue;
        }

        if(str[0] == 'n')
        st.dir = 0;
        else if(str[0] == 'e')
        st.dir = 1;
        else if(str[0] == 's')
        st.dir = 2;
        else if(str[0] == 'w')
        st.dir = 3;

        st.step = 0;

        int k;
        for(i = 0; i < M; i++)
            for(j = 0; j < N; j++)
                for(k = 0; k < 4; k++)
                    Flag[i][j][k] = false;
        BFS();
    }
}

