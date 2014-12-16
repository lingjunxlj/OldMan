/*

�����·���ϵ�ת����߶���
    ��ĳһ���ķ������������ĵ�ȫ�����(������),�����Ƚ����ȳ�...
    �Ϳ��Լ����һ�����˼�����.
    (���ַ���ʮ������!)
    ����������Ϸ"������"(һ��ֻ�ܹ�������,�������߶�).
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
}Point;//�Զ��������
queue<Point>Q;//���������,���int����
int w;//��ʾͼ�Ŀ��--����
int h;//��ʾͼ�ĳ���--����
int sx,sy;//ȫ�ֵĿ�ʼ����
int ex,ey;//ȫ�ֵ��յ�����
bool map[MAX][MAX];//ȫ�ֵ�ͼ����,���߾���true,������false
int value[MAX][MAX];//ȫ�ֵ�����ֵ,��¼�˴ӿ�ʼ�㵽���е�ͨ����Χ�����ʻ����,�����е�ͨvalue[][]��Ϊ-1
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};//�����������ĸ�����
//�жϵ��Ƿ����������ͼ����
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
    value[sx][sy]=0;//��ʼ������ʱ�����ֵΪ0
    while(!Q.empty()&&value[ex][ey]==-1)
    {
        //���ĸ���������
        for(int i=0;i<4;i++)
        {
            int tempx=Q.front().x+dir[i][0];
            int tempy=Q.front().y+dir[i][1];
            //��ĳһ���ķ������������ĵ�ȫ�����(������),�����Ƚ����ȳ�...
            while(In(tempx,tempy)&&map[tempx][tempy]&&value[tempx][tempy]==-1)
            {
                q.x=tempx;
                q.y=tempy;
                Q.push(q);//�������������п����Ե㶼�����
                //���������Ҫ����Ҫ�ص����
                value[tempx][tempy]=value[Q.front().x][Q.front().y]+1;
                tempx+=dir[i][0];
                tempy+=dir[i][1];
            }
        }
        Q.pop();// ɾ������Ԫ��
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
            printf("Pair %d: %d segments.\n",++ans2,value[ex][ey]);
            else
            printf("Pair %d: impossible.\n",++ans2);
            map[ex][ey]=false;//�������յ�����Ϊ������ͨ��
        }
        putchar(10);
    }
    return 0;
}
