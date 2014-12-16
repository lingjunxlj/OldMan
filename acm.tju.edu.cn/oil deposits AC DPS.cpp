#include<stdio.h>
#include<string.h>
char a[100][100];
int b[100][100],n,m;
int x[8]={1,1,1,0,0,-1,-1,-1},
    y[8]={1,0,-1,1,-1,1,0,-1};
void dfs(int i,int j)
{
	int k;
	int tx,ty;
	b[i][j]=0;
	for(k=0;k<8;k++)
	{
		tx=i+x[k];
		ty=j+y[k];
		if(tx >= 0 && tx <= n && ty >= 0 && ty <= m && 
			b[tx][ty] && a[tx][ty]=='@')
			dfs(tx,ty);
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
			for(j=0;j<m;j++)b[i][j]=1;
		num=0;
		for(i=0;i<n;i++)scanf("%s",&a[i]);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
			if(b[i][j]&&a[i][j]=='@')
			{
				num++;
				dfs(i,j);
			}
		printf("%d\n",num);
	}
	return 0;
}

