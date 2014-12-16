#include <cstdio>
#include <string>
char map[40][40][40];
bool flag[40][40][40],fg;
struct M
{
    int x,y,z,step;
}queue[64000];
int a,b,c,Time;
int d[6][3]=
{
    1,  0,  0,
   -1,  0,  0,
    0,  1,  0,
    0, -1,  0,
    0,  0, -1,
    0,  0,  1
};
int BFS(int a1,int b1,int c1)
{
    int head=0,top=0;
    int i,x,y,z,step;
    queue[top].x=a1;
    queue[top].y=b1;
    queue[top].z=c1;
    queue[top].step=0;
    top++;
    flag[a1][b1][c1]=0;
    while (head<top)
    {
        for (i=0;i<6;i++)
        {
            x= queue[head].x+d[i][0];
            y= queue[head].y+d[i][1];
            z= queue[head].z+d[i][2];
            step=queue[head].step+1;
            if (x<0||x>=a||y<0||y>=b||z<0||z>=c)
            continue;
            if (map[x][y][z]!='#'&&flag[x][y][z])
            {
                flag[x][y][z]=0;
                if (map[x][y][z]=='E')
                {
                    fg=1;
                    Time=step;
                    return 1;
                }
                queue[top].x=x;
                queue[top].y=y;
                queue[top].z=z;
                queue[top].step=step;
                top++;
            }
        }
        head++;
    }
}
int main()
{
    while(scanf("%d%d%d",&a,&b,&c)!=EOF&&a&&b&&c)
    {
        int i, j, k, x, y, z;
        for(i=0; i<a; ++i)
        for(j=0; j<b; ++j)
            scanf("%s", map[i][j]);

        for(i=0; i<a; ++i)
        for(j=0; j<b; ++j)
            for(k=0; k<c; ++k)
            {
                flag[i][j][k]=true;
                if(map[i][j][k]=='S')
                {
                    x= i;
                    y= j;
                    z= k;
                }
            }
        fg= false;
        BFS(x, y, z);
        if(fg)
            printf("Escaped in %d minute(s).\n", time);
        else
            printf("Trapped!\n");
    }
}

