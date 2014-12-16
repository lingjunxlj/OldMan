#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int bit[20];
int t[]={19,39,78,140,305,626,1252,2248,4880,10016,20032,35968,12544,29184,58368,51200};
int MIN;
int dir[4][2] =
{
     1,  0,
     0,  1,
    -1,  0,
     0, -1,
};
void before_hand()
{
    int i, j, k, temp, x, y, w;
    x = y = w = 0;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
        {

            temp = 0;
            temp ^= ( 1 << (i * 4 + j) );

            for (k = 0; k < 4; k++)
            {
                x = i + dir[k][0];
                y = j + dir[k][1];
                if (x < 0 || x > 3 || y < 0|| y > 3)
                continue;
                temp ^= ( 1 << (x * 4 + y) );
            }

            bit[w++] = temp;
        }
}
void DFS(int state, int num, int deep)
{
      if(deep > 15)
      {
              if(state == 0 || state == 65535)
              {
                      if(num<MIN)
                      MIN = num;
              }
              return;
      }
      DFS(state ^ t[deep], num + 1, deep + 1);
      DFS(state, num, deep + 1);
}
const int SIZE = 65535;

int BFS(int state)
{
        int visited[SIZE], d[SIZE], u, v, i;
        int Qu[SIZE], rear, front;
        memset(visited, 0, sizeof(visited));

        visited[state] = 1;
        d[state] = 0;
        rear = front = 0;
        Qu[++rear] = state;

        while(rear!=front)
        {
                u=Qu[++front];
                for(i = 0; i < 16; ++i)
                {
                        v = u ^ bit[i];
                        if(v == 0 || v == 65535)
                        return d[u] + 1;
                        if(visited[v] == 0)
                        {
                                visited[v] = 1;
                                d[v] = d[u] + 1;
                                Qu[++rear] = v;
                        }
                }
                visited[u] = -1;
        }
        return -1;
}

int main()
{
        before_hand();
        char ch[5][5];
        int i, j, start;
        while(scanf("%s",ch[0])!=EOF)
        {
                start = 0;
                MIN = 0xfffffff;
                for(i = 1; i < 4; ++i)
                        scanf("%s", ch[i]);

                for(i = 0; i < 4; ++i)
                    for(j = 0; j < 4; ++j)
                        if(ch[i][j] == 'b')
                            start ^= (1 << ( (3 - i) * 4 + (3 - j) ) );

                if(start == 0 || start == 65535)
                printf("0\n");
                else
                {
                    //DFS(start,0,0);
                    //MIN==0xfffffff?
                    //printf("Impossible\n"):printf("%d\n",MIN);
                    int result=BFS(start);
                    result==-1?printf("Impossible\n"):printf("%d\n",result);

                }
        }
        return 0;
}
