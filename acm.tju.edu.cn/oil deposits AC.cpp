#include<stdio.h>
#include<string.h>
char a[100][100];
int b[100][100],n,m;
int queue[10000][2];//x,y
int x[8]={1,1,1,0,0,-1,-1,-1};
int y[8]={1,0,-1,1,-1,1,0,-1};
void bfs(int i,int j)
{
	int k;
	int tx,ty;
	int cx,cy;
	int head=0,tail=1;
	queue[0][0]=i;
	queue[0][1]=j;
	b[i][j]=0;
	//b[i][j]=0;
	while(head<tail)
	{
		cx=queue[head][0];
		cy=queue[head][1];
		head++;
		for(k=0;k<8;k++)
		{
			tx=cx+x[k];
			ty=cy+y[k];
			if(tx >= 0 && tx <= n && ty >= 0 && ty <= m && 
				b[tx][ty] && a[tx][ty]=='@')
			{
				queue[tail][0]=tx;
				queue[tail][1]=ty;
				tail++;
				b[tx][ty]=0;
			}
		}
	}

}
int main()
{
	int i,j,num;
	while(1)
	{	
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)break;
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
        b[i][j]=1;
		num=0;
		for(i=0;i<n;i++)
        scanf("%s",&a[i]);
		for(i=0;i<n;i++)
		for(j=0;j<m;j++)
        if(b[i][j]&&a[i][j]=='@')
        {
            num++;
            bfs(i,j);
        }
		printf("%d\n",num);
	}
	return 0;
}
