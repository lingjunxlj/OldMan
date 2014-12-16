#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
const int MAX = 100;
bool flag[MAX][MAX];
int value[MAX][MAX];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int x1,y1,x2,y2,w,h;
typedef struct QU
{
    int x,y,step;
}QU;
queue<QU>Q;
bool FLAG(int x,int y)
{
    if(x<0||x>h+1||y<0||y>w+1)
    return false;
    return true;
}
int BFS()
{
    QU q;
    q.x=x1;
    q.y=y1;
    Q.push(q);
    value[x1][y1]=0;
    while(!Q.empty()&&value[x2][y2]==-1)
    {
        for(int i=0;i<4;i++)
        {
            int temp_x=Q.front().x+dir[i][0];
            int temp_y=Q.front().y+dir[i][1];
            while(FLAG(temp_x,temp_y)&&flag[temp_x][temp_y]&&value[temp_x][temp_y]==-1)
            {
                q.x=temp_x;
                q.y=temp_y;
                Q.push(q);
                value[temp_x][temp_y]=value[Q.front().x][Q.front().y]+1;
                temp_x+=dir[i][0];
                temp_y+=dir[i][1];
            }
        }
        Q.pop();
    }
    return value[x2][y2];
}
int main()
{
    int ans1=0,ans2;
    int i,j;
    char ch;
    while(scanf("%d%d",&w,&h)&&(w||h))
    {
        getchar();
        for(i=0;i<=w+1;i++)
        flag[0][i]=true;

        for(i=0;i<=w+1;i++)
        flag[h+1][i]=true;

        for(i=0;i<=h+1;i++)
        flag[i][0]=true;

        for(i=0;i<=h+1;i++)
        flag[i][w+1]=true;

        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
            {
                scanf("%c",&ch);
                if(ch==' ')
                flag[i][j]=true;
                else
                flag[i][j]=false;
            }
            getchar();
        }
        printf("Board #%d:\n",++ans1);
        ans2=0;
        while(scanf("%d%d%d%d",&y1,&x1,&y2,&x2)&& (x1||y1||x2||y2))
        {
            while(!Q.empty())
            {
                Q.pop();
            }
            memset(value,-1,sizeof(value));

            flag[x2][y2]=true;

            if(BFS()!=-1)
            printf("Pair %d: %d segments.\n",++ans2,value[x2][y2]);
            else
            printf("Pair %d: impossible.\n",++ans2);
            flag[x2][y2]=false;
        }
        printf("\n");
    }
    return 0;
}




