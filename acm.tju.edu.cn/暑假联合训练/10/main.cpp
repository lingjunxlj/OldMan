#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN=55;
const int MAXM=100000000;
char map[MAXN][MAXN];
bool flagA,flagB,flagD,flagE,flagC;
int n,m;
int Hurt;
int lenA,lenB,lenD,lenE;
int list[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool flag[MAXN][MAXN];

void dfs(int x,int y,int hurt)
{
	int i,j;
	for(j=0;j<4;j++)
	{
		if(map[x][y]=='#'||map[x][y]=='A'||map[x][y]=='B'||map[x][y]=='D'||map[x][y]=='E'||x<0||x>=n||y<0||y>=m||flag[x][y])
		return;

		if(map[x][y]=='C'&&!flagC)
		{
			hurt+=3;
			flagC=true;
		}
		int x2,y2;
		for(x2=x;abs(x-x2)<=2&&!flagA&&x2<n;x2++)
		{
			y2=y-(2-abs(x-x2));
			if(y2>=0&&y2<m&&map[x2][y2]=='A')
			{
				hurt+=1;
				flagA=true;
			}
		}
		for(x2=x;abs(x-x2)<=2&&!flagA&&x2>=0;x2--)
		{
			y2=y-(2-abs(x-x2));
			if(y2>=0&&y2<m&&map[x2][y2]=='A')
			{
				hurt+=1;
				flagA=true;
			}
		}
		for(x2=x;abs(x-x2)<=3&&!flagB&&x2<n;x2++)
		{
			y2=y-(3-abs(x-x2));
			printf("y2 += %d\n",y2);
			if(y2>=0&&y2<m&&map[x2][y2]=='B')
			{
				hurt+=2;
				flagB=true;
			}
		}
		for(x2=x;abs(x-x2)<=3&&!flagB&&x2>=0;x2--)
		{
			y2=y-(3-abs(x-x2));
			printf("y2 -= %d\n",y2);
			if(y2>=0&&y2<m&&map[x2][y2]=='B')
			{
				hurt+=2;
				flagB=true;
			}
		}
		for(x2=x;abs(x-x2)<=2&&!flagD&&x2<n;x2++)
		{
			y2=y-(2-abs(x-x2));
			if(y2>=0&&y2<m&&map[x2][y2]=='D')
			{
				hurt+=4;
				flagD=true;
			}
		}
		for(x2=x;abs(x-x2)<=2&&!flagD&&x2>=0;x2--)
		{
			y2=y-(2-abs(x-x2));

			if(y2>=0&&y2<m&&map[x2][y2]=='D')
			{
				hurt+=4;
				flagD=true;
			}
		}
		for(x2=x;abs(x-x2)<=1&&!flagE&&x2<n;x2++)
		{
			y2=y-(1-abs(x-x2));
			if(y2>=0&&y2<m&&map[x2][y2]=='E')
			{
				hurt+=5;
				flagE=true;
			}
		}
		for(x2=x;abs(x-x2)<=1&&!flagE&&x2>=0;x2--)
		{
			y2=y-(1-abs(x-x2));
			if(y2>=0&&y2<m&&map[x2][y2]=='E')
			{
				hurt+=5;
				flagE=true;
			}
		}

		if(Hurt==0) return;
		if(map[x][y]=='!' && map[x][y] != '$')
		{
			if(Hurt>hurt)
				Hurt=hurt;
		}
		flag[x][y]=true;
		dfs(x+list[j][0],y+list[j][1],hurt);
		flag[x][y]=false;

	}
}

int main()
{
	int t;
	int k=0;
	scanf("%d",&t);
	while(t--)
	{
		k++;
		memset(map,0,sizeof(map));
		memset(flag,false,sizeof(flag));
		flagA=flagB=flagC=flagD=flagE=false;
		lenA=lenB=lenD=lenE=0;
		Hurt=MAXM;
		int i,j,x,y;
		scanf("%d%d",&n,&m);
		getchar();
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%c",&map[i][j]);
				if(map[i][j]=='$')
				{
					x=i;
					y=j;
				}
			}
			getchar();
		}
		dfs(x,y,0);
		printf("Case %d: ",k);
		if(Hurt==MAXM)
		printf("-1\n");
		else
		printf("%d\n",Hurt);
	}
}

