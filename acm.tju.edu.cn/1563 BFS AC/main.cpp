#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct
{
    int x, y, z, step;
}queue[64000];

bool flag;
int l, r, c, time;
char G[40][40][40];
bool mark[40][40][40];
int d[6][3]={
    {-1, 0, 0},
    { 1, 0, 0},
    { 0,-1, 0},
    { 0, 1, 0},
    { 0, 0,-1},
    { 0, 0, 1}
};
bool bfs(int a, int b, int k)
{
    int head=0, top= 0;
    int x, y, z, i, step;
    queue[top].x= a; queue[top].y= b;
    queue[top].z= k; queue[top].step= 0;
    ++top;
    mark[a][b][k]= false;
    while(head<top)
    {
        for(i=0; i<6; ++i)
        {

            x= queue[head].x+d[i][0];
            y= queue[head].y+d[i][1];
            z= queue[head].z+d[i][2];
            step= queue[head].step+1;

            if(x<0|| y<0|| z<0|| x>=l|| y>=r|| z>=c)
            continue;

            if(G[x][y][z]!= '#'&& mark[x][y][z])
            {
                mark[x][y][z]= false;
                if(G[x][y][z]=='E')
                {
                    flag= true;
                    time= step;
                    return true;
                }

                queue[top].x= x;
                queue[top].y= y;
                queue[top].z= z;
                queue[top].step= step;
                ++top;
            }
        }
        ++head;
    }
}
int main()
{
    while(scanf("%d%d%d",&l,&r,&c)!=EOF&&l&&r&&c)
    {
        int i, j, k, x, y, z;
        for(i=0; i<l; ++i)
        for(j=0; j<r; ++j)
            scanf("%s", G[i][j]);

        for(i=0; i<l; ++i)
        for(j=0; j<r; ++j)
            for(k=0; k<c; ++k)
            {
                mark[i][j][k]=true;
                if(G[i][j][k]=='S')
                {
                    x= i;
                    y= j;
                    z= k;
                }
            }
        flag= false;
        bfs(x, y, z);
        if(flag)
            printf("Escaped in %d minute(s).\n", time);
        else
            printf("Trapped!\n");
    }
}
