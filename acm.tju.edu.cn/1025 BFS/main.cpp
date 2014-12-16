#include<iostream>
#include<queue>
using namespace std;
int m,n;
bool G[52][52],g[52][52][4];
struct Point
{
    //状态节点，坐标方向及消耗
    int i,j,f;
    int st;
}st,et,mt,nt;
int dx[4][3]={-1,-2,-3,0,0,0,1,2,3,0,0,0};//坐标向量，朝各个方
int dy[4][3]={0,0,0,1,2,3,0,0,0,-1,-2,-3};
void BFS()
{
    queue<Point>ptq;//利用队列先进先出的性质实现BFS
    ptq.push(st);//起点入队
    g[st.i][st.j][st.f]=1;
    while(!ptq.empty())
    {
        mt=ptq.front();
        ptq.pop();
        if(mt.i==et.i&&mt.j==et.j)
        {
            //到达目标节点
            printf("%d\n",mt.st);//输出当前消耗
            return ;//搜索结束
        }
        int f=mt.f;
        int stm=mt.st;
        nt.st=stm+1;
        nt.f=f;
        for(int i=0;i<3;i++)
        {
            //方向不变，向前走1m,2m,3m，时间加1
            nt.i=mt.i+dx[f][i];
            nt.j=mt.j+dy[f][i];
            if(nt.i<=0||nt.j<=0||nt.i>=m||nt.j>=n)
            break;
            if(G[nt.i][nt.j])
            break;
            if(g[nt.i][nt.j][nt.f])
            continue;//此状态已存在
            g[nt.i][nt.j][nt.f]=1;
            ptq.push(nt);
        }

        mt.st=stm+1;
        mt.f=f+1;//右转,方向变，时间加1，坐标不变
        if(mt.f>3)
        mt.f=0;
        if(!g[mt.i][mt.j][mt.f])
        {
            ptq.push(mt);
            g[mt.i][mt.j][mt.f]=1;
        }

        mt.st=stm+1;
        mt.f=f-1;//左转，方向变，时间加1，坐标不变
        if(mt.f<0)
        mt.f=3;
        if(!g[mt.i][mt.j][mt.f])
        {
            ptq.push(mt);
            g[mt.i][mt.j][mt.f]=1;
        }
    }
    printf("-1\n");
}
int main()
{
    int t=0;
    char f[10];
    while(scanf("%d%d",&m,&n)&&(m!=0||n!=0))
    {
        memset(G,0,sizeof(G));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&t);
                if(t)
                {
                    G[i][j]=1;
                    G[i][j+1]=1;
                    G[i+1][j]=1;
                    G[i+1][j+1]=1;
                }
            }
        scanf("%d%d%d%d%s",&st.i,&st.j,&et.i,&et.j,f);
        if(G[et.i][et.j])
        {
            printf("-1\n");
            continue;
        }
        if(f[0]=='n')
        st.f=0;
        else if(f[0]=='e')
        st.f=1;
        else if(f[0]=='s')
        st.f=2;
        else if(f[0]=='w')
        st.f=3;
        st.st=0;
        memset(g,0,sizeof(g));
        BFS();
    }
}
