#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int x, y;
    int dir;             //方向
}st, end;
struct node
{
	int up,down,left,right;
};
node map[N][N];
int n, m, in,out;
bool used[maxn][maxn][5];
int vis[510][510];
int temp[510][510];
bool check_dfs(node a,int dir)        //深搜的判断条件
{//没越界、不是墙、没走过
    if(a.x> = 1 && a.x<=n&&a.y>=1&&a.y<=m &&!used[a.x][a.y][dir])
        return true;
    return false;
}
int dir_r[4][2]={{1,0},{0,1},{-1,0},{0,-1}};            //如果可以不要这个，只需下面for 列举方向时从大到小就行了
void dfs_r(node a)              //沿右边界走，方法同上
{
    if(a.x==end.x && a.y==end.y)
        return;
    node u;
    a.dir=(a.dir+3)%4;
    for(int i=0;i<4;i++)
    {
        u.dir=(a.dir+i)%4;
        u.x=a.x+dir_r[u.dir][0];
        u.y=a.y+dir_r[u.dir][1];
        //u.step=a.step+1;
        if(check_dfs(u,u.dir))
        {
            used[u.x][u.y][u.dir]=true;
            vis[u.x][u.y] = 1;
            int tmp=dfs_r(u);
            if(tmp)
            {
                used[u.x][u.y][u.dir]=false;
                return tmp;
            }
            used[u.x][u.y][u.dir]=false;
        }
    }
    return 0;
}


int main()
{
	int i,j;
	int row;
	int cas;
	scanf("%d", &cas);
	while(cas--)
	{
		scanf("%d%d",&n,&m);
		cin>>in>>out;
		in++;
		out++;
		for(i=1;i<=n;i++)
		    for(j=1;j<=m;j++)
		    {
				map[i][j].up=map[i][j].down=map[i][j].left=map[i][j].right=1;
			}
		row=1;
		int flag;
		while(row<=n)
		{
			for(i=1;i<m;i++)
			{
				scanf("%d",flag);
				map[row][i].right=flag;
				if(i+1<=m)
				    map[row][i+1].left=flag;
			}
			if(row<n)
			{
				for(i=1;i<=m;i++)
				{
					scanf("%d",flag);
					map[row][i].down=flag;
					if(row+1<=n)
					    map[row+1][i].up=flag;
				}
			}
			st.x = 1;
			st.y = in;

			end.x = n;
			end.y = out;

			st.dir = 3;

			memset(used,false,sizeof(used));           //沿右边
            used[st.x][st.y][st.dir]=true;
            dfs_r(st);
		}
	}
}
