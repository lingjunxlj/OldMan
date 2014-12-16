/*

求最短路径上的转弯的线段数
    在某一个的方向上所经历的点全部入队(不超界),再让先进的先出...
    就可以计算出一共拐了几次弯.
    (这种方法十分巧妙!)
    这类似于游戏"连连看"(一次只能拐两个弯,共三条线段).
*/
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int MAX=80;
typedef struct Point
{
    int x;
    int y;
}Point;//自定义点坐标
queue<Point>Q;//定义个队列,存放int型数
int w;//表示图的宽度--列数
int h;//表示图的长度--行数
int sx,sy;//全局的开始坐标
int ex,ey;//全局的终点坐标
bool map[MAX][MAX];//全局的图坐标,能走就是true,否则是false
int value[MAX][MAX];//全局的搜索值,记录了从开始点到能行的通的周围点的行驶距离,不能行的通value[][]则为-1
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//代表搜索的四个方向
//判断点是否在所允许的图面上
bool In(int x,int y)
{
    if(x<0||x>h+1||y<0||y>w+1)
    return false;
    return true;
}
int BFS()
{
    Point q;
    q.x=sx,q.y=sy;
    Q.push(q);
    value[sx][sy]=0;//开始搜索的时候距离值为0
    while(!Q.empty()&&value[ex][ey]==-1)
    {
        //往四个方向搜索
        for(int i=0;i<4;i++)
        {
            int tempx=Q.front().x+dir[i][0];
            int tempy=Q.front().y+dir[i][1];
            //在某一个的方向上所经历的点全部入队(不超界),再让先进的先出...
            while(In(tempx,tempy)&&map[tempx][tempy]&&value[tempx][tempy]==-1)
            {
                q.x=tempx;
                q.y=tempy;
                Q.push(q);//将这个方向的所有可行性点都入队列
                //这句代码很重要，需要重点理解
                value[tempx][tempy]=value[Q.front().x][Q.front().y]+1;
                tempx+=dir[i][0];
                tempy+=dir[i][1];
            }
        }
        Q.pop();// 删除队首元素
    }
    return value[ex][ey];
}
int main()
{
    int ans1=0,ans2;
    int i,j;
    char ch;
    while(scanf("%d%d",&w,&h)&&(w||h))//h行,w列
    {
        getchar();//吸收回车字符
        for(i=0;i<=w+1;i++)
        map[0][i]=true;//第0行能走
        for(i=0;i<=w+1;i++)
        map[h+1][i]=true;//第h+1行能走
        for(i=0;i<=h+1;i++)
        map[i][0]=true;//第0列能走
        for(i=0;i<=h+1;i++)
        map[i][w+1]=true;//第w+1列能走
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=w;j++)
            {
                scanf("%c",&ch);
                if(ch==' ')
                map[i][j]=true;
                else
                map[i][j]=false;
            }
            getchar();//吸收回车字符
        }
        printf("Board #%d:\n",++ans1);
        ans2=0;
        while(scanf("%d%d%d%d",&sy,&sx,&ey,&ex)&& (sx||sy||ex||ey))//注意输入坐标的顺序，先Y后X!
        {
            while(!Q.empty())
            Q.pop();//清空队列,为下次搜索做准备
            memset(value,-1,sizeof(value));//每次搜索前都所有点到开始点的搜索距离都是-1
            map[ex][ey]=true;//搜索前将终点设置为可以通行
            if(BFS()!=-1)
            printf("Pair %d: %d segments.\n",++ans2,value[ex][ey]);
            else
            printf("Pair %d: impossible.\n",++ans2);
            map[ex][ey]=false;//搜索后将终点设置为不可以通行
        }
        putchar(10);
    }
    return 0;
}
