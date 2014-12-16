#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct point
{
       int x,y,pre;
       char dir;
}q[20000];
bool u[140][140];
int G[140][140];
int print(int id)
{
       if(q[id].pre==-1)
       return 0 ;
       else
       {
              print(q[id].pre);
              printf("%c ",q[id].dir);
       }
}
int main()
{
    int n;
    cin>>n;
    while (n--)
    {
        int i,j,k,sx,sy,x1,y1,x2,y2,l,r,x,y;
        int R ,L;
        cin>>R>>L;
        for (i = 0; i < R ;i++)
        for (j = 0; j < L ;j++)
        cin>>G[i][j];
        cin>>sx>>sy;
        q[0].x=sx-1;
        q[0].y=sy-1;
        q[0].pre=-1;
        l=0;
        r=1;
        memset(u,true,sizeof(u));
        u[sx][sy]=false;
        while(l<r)
        {
            x=q[l].x;
            y=q[l].y;
            if(G[x][y]==0&&(x==0 || x==R-1|| y==0|| y==L-1))
            break;
            if(x+1<R && u[x+1][y]&&G[x+1][y]==0)
            {
                u[x+1][y]=false;
                q[r].x=x+1;
                q[r].y=y;
                q[r].pre=l;
                q[r].dir='D';
                r++;
            }
            if(x-1>=0 &&  u[x-1][y] && G[x-1][y]==0)
            {
                u[x-1][y]=false;
                q[r].x=x-1;
                q[r].y=y;
                q[r].pre=l;
                q[r].dir='U';
                r++;
            }
            if(y+1<L &&  u[x][y+1] && G[x][y+1]==0)
            {
                u[x][y+1]=false;
                q[r].x=x;
                q[r].y=y+1;
                q[r].pre=l;
                q[r].dir='R';
                r++;
            }
            if(y-1>=0  && u[x][y-1] && G[x][y-1]==0)
            {
                u[x][y-1]=false;
                q[r].x=x;
                q[r].y=y-1;
                q[r].pre=l;
                q[r].dir='L';
                r++;
            }
            l++;

        }
        print(l);
        if (x==0)
        printf("U");
        if (x==R-1)
        printf("D");
        if (y==0)
        printf("L");
        if (y==L-1)
        printf("R");
        printf("\n");
    }
    return 0;
}
