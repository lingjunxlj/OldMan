#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct XBlock
{
    int x;
    int starty, endy;
};

struct YBlock
{
    int y;
    int startx, endx;

};

XBlock bx[2501];
YBlock yb[2501];
char map[51][51];
char temp[51][51];
int casen, n, m, bxn, byn, match;
bool connect[2501][2501];
bool state[1501];
int res[1501];

void copy()
{
    int i,j;
    for( i = 1; i <= n ; i++)
        for( j = 1; j <= m; j++)
            temp[i][j] = map[i][j];

}
void MakeXBlock()
{
    int i, j, t;
    bxn = 0; //��¼bx[]���±�
    for( i = 1; i <= n ; i++)
        for( j = 1; j <= m; j++)
            if(temp[i][j] == 'o')
            {
                bxn ++;
                bx[bxn].x = i;
                for( t = j; t > 0; t--)//ȷ����������ʼ����
                {
                    if(temp[i][t] == '#')
                    {
                        bx[bxn].starty = t+1;
                        break;
                    }
                    else
                    {
                        bx[bxn].starty = t;
                        if(temp[i][t] == 'o' && t != j) //ɾ����һ���е�������o��
                            temp[i][t] = 'x';
                    }
                }

                for( t = j; t <= m; t++ )//ȷ�������Ľ�������
                {
                    if(temp[i][t] == '#')
                    {
                        bx[bxn].endy = t-1;
                        break;
                    }
                    else
                    {
                        bx[bxn].endy = t;
                        if(temp[i][t] == 'o' && t != j )  //ɾ����һ���е�������o��
                            temp[i][t] = 'x';
                    }
                }

            }
}

void MakeYBlock()
{
    int i, j, t;
    byn = 0;
    for(j = 1; j <= m ;j++)
        for(i = 1; i <= n; i++)
            if(temp[i][j] == 'o')
            {
                byn++;
                yb[byn].y = j;
                for(t = i ; t > 0 ; t--) //ȷ����������ʼ����
                {
                    if(temp[t][j] == '#')
                    {
                        yb[byn].startx  = t+1;
                        break;
                    }
                    else
                    {
                        yb[byn].startx = t;
                        if(temp[t][j] == 'o' && t != i) //ɾ����һ���е�������o��
                            temp[t][j] = 'x';
                    }
                }

                for( t = i; t <= n; t++ )//ȷ�������Ľ�������
                {
                    if(temp[t][j] == '#')
                    {
                        yb[byn].endx  = t-1;
                        break;
                    }
                    else
                    {
                        yb[byn].endx  = t;
                        if(temp[t][j] == 'o' && t != i ) //ɾ����һ���е�������o��
                            temp[t][j] = 'x';
                    }
                }
            }
}
bool find(int i)    //�������㷨���������ƥ�����
{
    int j;
    for(j = 1; j <= byn; j++)
        if(connect[i][j] == true && state[j] == false)
        {
            state[j] = true;
            if(res[j] == 0 || find (res[j]) == true)
            {
                res[j] = i;
                return true;
            }
        }
        return false;
}


int main()
{
    cin>>casen;
    int i, j, num = casen;
    while(num--)
    {
        cin>>n>>m;
        for( i = 1; i <= n ; i++)
            for( j = 1; j <= m; j++)
                cin>>map[i][j];

        for( i = 1; i <= 1500; i++) // ��ʼ���ṹ���������
        {
            bx[i].endy = bx[i].starty = bx[i].x = 0;
            yb[i].endx = yb[i].startx = yb[i].y = 0;
        }
        copy();
        MakeXBlock();//��������
        copy();
        MakeYBlock(); //���������
        memset(connect, false, sizeof(connect));
        memset(res, 0 , sizeof(res));
        for(i = 1; i <= bxn; i++) //�����ڽӾ���
            for(j = 1; j <= byn; j++)
            {
                if((bx[i].x >= yb[j].startx && bx[i].x <= yb[j].endx) &&( yb[j].y >= bx[i].starty && yb[j].y <= bx[i].endy ) && map[bx[i].x][yb[j].y] == 'o')
                    connect[i][j] = true;
            }
        match = 0;
        for(i = 1; i <= bxn; i++) //�������ƥ����
        {
            memset(state, false, sizeof(state));
            if(find(i))
                match++;
        }
        cout<<"Case :"<<casen- num<<endl;
        cout<<match<<endl;

    }
    return 0;
}
