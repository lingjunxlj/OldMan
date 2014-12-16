#include<stdio.h>
#include<string.h>
struct IN
{
    int x;
    int y;
}Q[100000];
int d[300][300];
char color[300][300];
int start_x,start_y,end_x,end_y,n;
void search()
{
    int k1,k2,u_x,u_y;
    memset(color,'W',sizeof(color));
    color[start_x][start_y]='G';
    d[start_x][start_y]=0;
    k1=0;
    k2=0;
    Q[k1].x=start_x;
    Q[k1].y=start_y;
    k1++;
    do{
        u_x=Q[k2].x;
        u_y=Q[k2].y;
        k2++;
        if(u_x-1>=0&&u_y+2<n&&color[u_x-1][u_y+2]=='W')
        {
            color[u_x-1][u_y+2]='G';
            d[u_x-1][u_y+2]=d[u_x][u_y]+1;
            Q[k1].x=u_x-1;
            Q[k1].y=u_y+2;
            k1++;
        }
        if(u_x-2>=0&&u_y+1<n&&color[u_x-2][u_y+1]=='W')
        {
            color[u_x-2][u_y+1]='G';
            d[u_x-2][u_y+1]=d[u_x][u_y]+1;
            Q[k1].x=u_x-2;
            Q[k1].y=u_y+1;
            k1++;
        }
        if(u_x-2>=0&&u_y-1>=0&&color[u_x-2][u_y-1]=='W')
        {
            color[u_x-2][u_y-1]='G';
            d[u_x-2][u_y-1]=d[u_x][u_y]+1;
            Q[k1].x=u_x-2;
            Q[k1].y=u_y-1;
            k1++;
        }
        if(u_x-1>=0&&u_y-2>=0&&color[u_x-1][u_y-2]=='W')
        {
            color[u_x-1][u_y-2]='G';
            d[u_x-1][u_y-2]=d[u_x][u_y]+1;
            Q[k1].x=u_x-1;
            Q[k1].y=u_y-2;
            k1++;
        }
        if(u_x+1<n&&u_y+2<n&&color[u_x+1][u_y+2]=='W')
        {
            color[u_x+1][u_y+2]='G';
            d[u_x+1][u_y+2]=d[u_x][u_y]+1;
            Q[k1].x=u_x+1;
            Q[k1].y=u_y+2;
            k1++;
        }
        if(u_x+2<n&&u_y+1<n&&color[u_x+2][u_y+1]=='W')
        {
            color[u_x+2][u_y+1]='G';
            d[u_x+2][u_y+1]=d[u_x][u_y]+1;
            Q[k1].x=u_x+2;
            Q[k1].y=u_y+1;
            k1++;
        }
        if(u_x+2<n&&u_y-1>=0&&color[u_x+2][u_y-1]=='W')
        {
            color[u_x+2][u_y-1]='G';
            d[u_x+2][u_y-1]=d[u_x][u_y]+1;
            Q[k1].x=u_x+2;
            Q[k1].y=u_y-1;
            k1++;
        }
        if(u_x+1<n&&u_y-2>=0&&color[u_x+1][u_y-2]=='W')
        {
            color[u_x+1][u_y-2]='G';
            d[u_x+1][u_y-2]=d[u_x][u_y]+1;
            Q[k1].x=u_x+1;
            Q[k1].y=u_y-2;
            k1++;
        }
        color[u_x][u_y]='B';    
    }while(k1!=k2);
}
int main()
{
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        while(N--)
        {
            scanf("%d",&n);
            scanf("%d %d",&start_x,&start_y);
            scanf("%d %d",&end_x,&end_y);
            search();
            printf("%d\n",d[end_x][end_y]);
        }
    }
    return 0;
}

