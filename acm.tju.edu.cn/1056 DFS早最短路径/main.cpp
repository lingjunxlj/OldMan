#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=1001;
int Fx[4][2]={0,1,1,0,0,-1,-1,0};
int fx,fy,sum,res,n,m;
char map[MAX][MAX];
bool flag[MAX][MAX];
void DFS(int x,int y)
{
    int i,x1,y1;
    for (i=0;i<4;i++)
    {
        x1=x+Fx[i][0];
        y1=y+Fx[i][1];
        if (x1<=n&&x1>=0&&y1<=m&&y1>=0&&map[x1][y1]=='0'&&!flag[x1][y1])
        {
            flag[x1][y1]=1;
            sum++;
            if (res<sum)
            {
                res=sum;
                fx=x1;
                fy=y1;
            }
            DFS(x1,y1);
            sum--;
            flag[x1][y1]=1;
        }
    }

}
int main()
{
    int x;
    scanf("%d",&x);
    while (x--)
    {
        memset(flag,0,sizeof(flag));
        int i,j;
        scanf("%d %d",&n,&m);
        for (i=0;i<m;i++)
        scanf("%s",map[i]);
        for (i=0;i<m;i++)
        for (j=0;j<n;j++)
        int a,b;
        scanf("%d %d",&a,&b);

            {
                flag[a][b]=1;
                sum=0;
                res=0;
                DFS(a,b);
                goto A;
            }

        A:;
        memset(flag,0,sizeof(flag));
        sum=0;
        res=0;
        flag[fx][fy]=1;
        DFS(fx,fy);
        printf("Maximum rope length is %d.\n",res);
    }
}


