#include<iostream>
#include<queue>
using namespace std;
struct Node
{
    int vi,vj;
    int time;//剩余时间
    int step;//花费时间
};
int gra[9][9];
int mark[9][9];//走到i、j所剩余的时间
int m,n,mins;
int si,sj,ei,ej;
int dir[4][2]={-1,0,1,0,0,-1,0,1};

void bfs()
{
    int k;
    Node p,q;
    queue<Node>Q;
    p.step = 0;
    p.time = 6;
    p.vi = si;
    p.vj = sj;
    Q.push(p);
    mark[si][sj] = p.time;
    while(!Q.empty())
    {
        q = Q.front();
        Q.pop();
        if(q.vi == ei && q.vj == ej)
        {
            if(q.time > 0 )
            {//跑掉
                mins = q.step;
                return ;
            }
            else
                continue;
        }
        if(gra[q.vi][q.vj] == 4) //时间重置
        {
            mark[q.vi][q.vj] = 6;
            q.time = 6;
        }
        for(k=0;k<4;k++)
        {
            p.vi = q.vi + dir[k][0];
               p.vj = q.vj + dir[k][1];
            p.time = q.time - 1;
            p.step = q.step + 1;
            if(p.vi>=0 && p.vi<m && p.vj>=0 && p.vj<n && gra[p.vi][p.vj]!=0 && q.time > 0
                && mark[p.vi][p.vj] < p.time)//不超界又不是墙
            {
                mark[p.vi][p.vj] = p.time;
                Q.push(p);
            }
        }//for(k=0;k<4;k++)
    }//while(!Q.empty())
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        int i,j;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                cin>>gra[i][j];
                if(gra[i][j] == 2)//起点
                {
                    si = i;
                    sj = j;
                }
                else if(gra[i][j] == 3)//终点
                {
                    ei = i;
                    ej = j;
                }
                mark[i][j] = 0;
            }
        }

        mins = 1000;
        bfs();
        if(mins != 1000) //逃掉
            cout<<mins<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
