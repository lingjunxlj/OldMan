/*
详细用法:
定义一个queue的变量     queue<Type> M
查看是否为空范例        M.empty()    是的话返回1，不是返回0;
从已有元素后面增加元素 M.push()
输出现有元素的个数      M.size()
显示第一个元素          M.front()
显示最后一个元素        M.back()
清除第一个元素          M.pop()
*/

/*
很很很经典的bfs,感受颇深:
面用bfs来解决从一个点到另一个点的最短路程长度的方法(写的有点冗杂)
注意的几点:
    1.为什么用bfs而不是dfs来解决最短路径长度问题?
        dfs搜索到另一个点后将所经历的点设为visited,不能再次访问;
        而bfs是宽度优先的策略,则可以涉及每一条路径.
        故,求一个可行解的问题(判断是否有路径)的问题适于用dfs,
        最优解,最短路径等求优化解的问题适于用bfs.
    2.怎样求最短路径长度?
        用一个等大的二维数组记录,记录到达所经过的每一点的路径长度,最先到达的距离最短.
*/
//CODE：
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
int w;//表示图的宽度
int h;//表示图的长度
int sx,sy;//全局的开始坐标
int ex,ey;//全局的终点坐标
bool map[MAX][MAX];//全局的图坐标,能走就是true,否则是false
int value[MAX][MAX];//全局的搜索值,记录了从开始点到能行的通的周围点的行驶距离,不能行的通value[][]则为-1
int BFS()
{
    Point q;//过渡点
    q.x=sx,q.y=sy;
    Q.push(q);//开始的点入队列
    value[sx][sy]=0;
    while(!Q.empty())//当队列为空结束
    {
        q=Q.front();//出队列的首元素
        sx=q.x,sy=q.y;
        if(sx==ex&&sy==ey)
        break;//搜索到终点结束循环,不需要再进行广度搜索了
        Q.pop();//队列的队首元素出队列
        //下面是四个方向的广度搜索--注意边界!
        if(sx-1>=0&&value[sx-1][sy]==-1&&map[sx-1][sy])//向上搜索
        {
            q.x=sx-1,q.y=sy;
            Q.push(q);
            value[sx-1][sy]=value[sx][sy]+1;
        }
        if(sy-1>=0&&value[sx][sy-1]==-1&&map[sx][sy-1])//向左搜索
        {
            q.x=sx,q.y=sy-1;
            Q.push(q);
            value[sx][sy-1]=value[sx][sy]+1;
        }
        if(sx+1<=h+1&&value[sx+1][sy]==-1&&map[sx+1][sy])//向下搜索
        {
            q.x=sx+1,q.y=sy;
            Q.push(q);
            value[sx+1][sy]=value[sx][sy]+1;
        }
        if(sy+1<=w+1&&value[sx][sy+1]==-1&&map[sx][sy+1])//向右搜索
        {
            q.x=sx,q.y=sy+1;
            Q.push(q);
            value[sx][sy+1]=value[sx][sy]+1;
        }
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
                printf("Pair %d: %d segments.\n",++ans2,value[ex][ey]-1);
                else
                printf("Pair %d: impossible.\n",++ans2);
                map[ex][ey]=false;//搜索后将终点设置为不可以通行
            }
            putchar(10);
        }
    return 0;
}

