/*
��ϸ�÷�:
����һ��queue�ı���     queue<Type> M
�鿴�Ƿ�Ϊ�շ���        M.empty()    �ǵĻ�����1�����Ƿ���0;
������Ԫ�غ�������Ԫ�� M.push()
�������Ԫ�صĸ���      M.size()
��ʾ��һ��Ԫ��          M.front()
��ʾ���һ��Ԫ��        M.back()
�����һ��Ԫ��          M.pop()
*/

/*
�ܾܺܺ����bfs,��������:
����bfs�������һ���㵽��һ��������·�̳��ȵķ���(д���е�����)
ע��ļ���:
    1.Ϊʲô��bfs������dfs��������·����������?
        dfs��������һ������������ĵ���Ϊvisited,�����ٴη���;
        ��bfs�ǿ�����ȵĲ���,������漰ÿһ��·��.
        ��,��һ�����н������(�ж��Ƿ���·��)������������dfs,
        ���Ž�,���·�������Ż��������������bfs.
    2.���������·������?
        ��һ���ȴ�Ķ�ά�����¼,��¼������������ÿһ���·������,���ȵ���ľ������.
*/
//CODE��
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int MAX=80;
typedef struct Point
{
    int x;
    int y;
}Point;//�Զ��������
queue<Point>Q;//���������,���int����
int w;//��ʾͼ�Ŀ��
int h;//��ʾͼ�ĳ���
int sx,sy;//ȫ�ֵĿ�ʼ����
int ex,ey;//ȫ�ֵ��յ�����
bool map[MAX][MAX];//ȫ�ֵ�ͼ����,���߾���true,������false
int value[MAX][MAX];//ȫ�ֵ�����ֵ,��¼�˴ӿ�ʼ�㵽���е�ͨ����Χ�����ʻ����,�����е�ͨvalue[][]��Ϊ-1
int BFS()
{
    Point q;//���ɵ�
    q.x=sx,q.y=sy;
    Q.push(q);//��ʼ�ĵ������
    value[sx][sy]=0;
    while(!Q.empty())//������Ϊ�ս���
    {
        q=Q.front();//�����е���Ԫ��
        sx=q.x,sy=q.y;
        if(sx==ex&&sy==ey)
        break;//�������յ����ѭ��,����Ҫ�ٽ��й��������
        Q.pop();//���еĶ���Ԫ�س�����
        //�������ĸ�����Ĺ������--ע��߽�!
        if(sx-1>=0&&value[sx-1][sy]==-1&&map[sx-1][sy])//��������
        {
            q.x=sx-1,q.y=sy;
            Q.push(q);
            value[sx-1][sy]=value[sx][sy]+1;
        }
        if(sy-1>=0&&value[sx][sy-1]==-1&&map[sx][sy-1])//��������
        {
            q.x=sx,q.y=sy-1;
            Q.push(q);
            value[sx][sy-1]=value[sx][sy]+1;
        }
        if(sx+1<=h+1&&value[sx+1][sy]==-1&&map[sx+1][sy])//��������
        {
            q.x=sx+1,q.y=sy;
            Q.push(q);
            value[sx+1][sy]=value[sx][sy]+1;
        }
        if(sy+1<=w+1&&value[sx][sy+1]==-1&&map[sx][sy+1])//��������
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
        while(scanf("%d%d",&w,&h)&&(w||h))//h��,w��
        {
            getchar();//���ջس��ַ�
            for(i=0;i<=w+1;i++)
            map[0][i]=true;//��0������
            for(i=0;i<=w+1;i++)
            map[h+1][i]=true;//��h+1������
            for(i=0;i<=h+1;i++)
            map[i][0]=true;//��0������
            for(i=0;i<=h+1;i++)
            map[i][w+1]=true;//��w+1������
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
                getchar();//���ջس��ַ�
            }
            printf("Board #%d:\n",++ans1);
            ans2=0;
            while(scanf("%d%d%d%d",&sy,&sx,&ey,&ex)&& (sx||sy||ex||ey))//ע�����������˳����Y��X!
            {
                while(!Q.empty())
                Q.pop();//��ն���,Ϊ�´�������׼��
                memset(value,-1,sizeof(value));//ÿ������ǰ�����е㵽��ʼ����������붼��-1
                map[ex][ey]=true;//����ǰ���յ�����Ϊ����ͨ��
                if(BFS()!=-1)
                printf("Pair %d: %d segments.\n",++ans2,value[ex][ey]-1);
                else
                printf("Pair %d: impossible.\n",++ans2);
                map[ex][ey]=false;//�������յ�����Ϊ������ͨ��
            }
            putchar(10);
        }
    return 0;
}

