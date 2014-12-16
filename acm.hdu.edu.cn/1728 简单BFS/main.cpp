#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;
const int MAXN = 101;
int move[4][2] =
{
    { 0,  1},
    { 1,  0},
    {-1,  0},
    { 0, -1}
};
struct Node
{
    int x;
    int y;
}temp, front;
char map[MAXN][MAXN];
bool flag[MAXN][MAXN];
int n, m;
int st_x, st_y, end_x, end_y, k, temp_k[MAXN][MAXN], k_used;
bool BFS()
{
    queue <struct Node> Queue;
    memset(temp_k, -1, sizeof(temp_k));
    k_used = 0;
    front.x = st_x;
    front.y = st_y;
    Queue.push(front);

    while(!Queue.empty())
    {
        front = Queue.front();
        Queue.pop();
        k_used = temp_k[front.x][front.y] + 1;
        if (k_used > k)
            break;
        for (int i = 0; i < 4; i++)
        {
            temp.x = front.x + move[i][0];
            temp.y = front.y + move[i][1];
            while(temp.x >= 0 && temp.x < n && temp.y >= 0 && temp.y < m && map[temp.x][temp.y]=='.')
            {
                if(temp_k[temp.x][temp.y] == -1)
                {
                    if(temp.x == end_x && temp.y == end_y && k_used <= k)
                        return true;
                    Queue.push(temp);
                    temp_k[temp.x][temp.y] = k_used;
                }
                temp.x += move[i][0];
                temp.y += move[i][1];
            }
        }

    }
    return false;

}
int main()
{
   int t;
   cin>>t;
   //getchar();
   while(t--)
   {
        cin>>n>>m;

        //memset(map, 0, sizeof(map));
        //memset(flag, 0, sizeof(flag));
        k_used = 0;

        for (int i = 0; i < n; i++)
            cin>>map[i];
        cin>>k>>st_y>>st_x>>end_y>>end_x;
        if(st_x == end_x && st_y == end_y)
        {
            printf("yes\n");
            continue;
        }
        st_x--;
        st_y--;
        end_x--;
        end_y--;
        if(BFS())
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
