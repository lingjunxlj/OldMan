#include<iostream>
#include<queue>
using namespace std;
int m,n;
bool G[52][52],g[52][52][4];
struct Point
{
    //״̬�ڵ㣬���귽������
    int i,j,f;
    int st;
}st,et,mt,nt;
int dx[4][3]={-1,-2,-3,0,0,0,1,2,3,0,0,0};//������������������
int dy[4][3]={0,0,0,1,2,3,0,0,0,-1,-2,-3};
void BFS()
{
    queue<Point>ptq;//���ö����Ƚ��ȳ�������ʵ��BFS
    ptq.push(st);//������
    g[st.i][st.j][st.f]=1;
    while(!ptq.empty())
    {
        mt=ptq.front();
        ptq.pop();
        if(mt.i==et.i&&mt.j==et.j)
        {
            //����Ŀ��ڵ�
            printf("%d\n",mt.st);//�����ǰ����
            return ;//��������
        }
        int f=mt.f;
        int stm=mt.st;
        nt.st=stm+1;
        nt.f=f;
        for(int i=0;i<3;i++)
        {
            //���򲻱䣬��ǰ��1m,2m,3m��ʱ���1
            nt.i=mt.i+dx[f][i];
            nt.j=mt.j+dy[f][i];
            if(nt.i<=0||nt.j<=0||nt.i>=m||nt.j>=n)
            break;
            if(G[nt.i][nt.j])
            break;
            if(g[nt.i][nt.j][nt.f])
            continue;//��״̬�Ѵ���
            g[nt.i][nt.j][nt.f]=1;
            ptq.push(nt);
        }

        mt.st=stm+1;
        mt.f=f+1;//��ת,����䣬ʱ���1�����겻��
        if(mt.f>3)
        mt.f=0;
        if(!g[mt.i][mt.j][mt.f])
        {
            ptq.push(mt);
            g[mt.i][mt.j][mt.f]=1;
        }

        mt.st=stm+1;
        mt.f=f-1;//��ת������䣬ʱ���1�����겻��
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
