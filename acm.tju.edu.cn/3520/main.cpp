#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct
{
    int x, y,step,pre;
    char dir;
}queue[64000];
bool flag;
int l, r , Time;
int G[140][140];
bool mark[140][140];
int d[4][2]={
    {-1, 0},
    { 1, 0},
    { 0,-1},
    { 0, 1},
};
int print(int id)
{
    if(queue[id].pre==-1)
    return 0;
    else
    {
        print(queue[id].pre);
        printf("%c ",queue[id].dir);
    }
}
void bfs(int a, int b)
{
    printf("BFS\n");
    int head=0, top= 0;
    int x, y, i, step;
    queue[top].x= a; queue[top].y= b;
    queue[top].step= 0;
    queue[top].pre=-1;
    ++top;
    mark[a][b]= false;
    while(head<top)
    {
        cout<<"shu chu"<<endl;
        for(i=0; i < 4; ++i)
        {
            cout<<"shu chu 1"<<endl;
            x= queue[head].x+d[i][0];
            y= queue[head].y+d[i][1];
            cout<<"x = "<<x<<"   "<<"y = "<<y<<endl;
            step= queue[head].step+1;

            if(x<0|| y<0|| x >= l|| y >= r)
            {
                cout<<"continue"<<endl;
                continue;
            }

            if(G[x][y] != 1 && mark[x][y])
            {
                mark[x][y] = false;
                if(G[x][y]== 0 &&(x==(l-1)||(x==0)||(y==0)||y==(r-1)))
                {
                    flag= true;
                    Time= step;
                    return ;
                }
                queue[top].x= x;
                queue[top].y= y;
                queue[top].step= step;
                if (i==0)
                queue[top].pre='L';
                if (i==1)
                queue[top].pre='R';
                if (i==2)
                queue[top].pre='D';
                if (i==3)
                queue[top].pre='U';
                ++top;
                printf("E: %d/n",top);
            }
        }
        ++head;
    }
}
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int i,j;
        cin>>r>>l;
        for (i = 0; i < r ;i++)
        for (j = 0; j < l ;j++)
        cin>>G[i][j];
        int bx,by;
        cin>>bx>>by;
        cout<<bx<<"------"<<by<<endl;
        bfs(bx,by);
        cout<<"Time=="<<Time<<endl;
        print(Time);
        printf("\n");
    }
    system("pause");
}



