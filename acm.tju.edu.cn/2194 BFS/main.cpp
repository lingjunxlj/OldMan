#include<iostream>
using namespace std;
int main()
{

    int i,j,k,n,m;
    int num;
    int dir[9][2];
    dir[1][0]=-1;dir[1][1]=0;
    dir[2][0]=-1;dir[2][1]=1;
    dir[3][0]=0;dir[3][1]=1;
    dir[4][0]=1;dir[4][1]=1;
    dir[5][0]=1;dir[5][1]=0;
    dir[6][0]=1;dir[6][1]=-1;
    dir[7][0]=0;dir[7][1]=-1;
    dir[8][0]=-1;dir[8][1]=-1;

    char  a[102][102];
    char  ans[102][102];
    int b[102][102];
    int q[20000][2];
    while(cin>>n>>m)
    {
        if (n==0&&m==0)
        break;
        for (i=0;i<=n+1;i++)
        {
            for (j=0;j<=n+1;j++)
            {
                ans[i][j]='.';
                a[i][j]='.';
            }
        }
        int x1,y1,x,y;
        for (k=0;k<m;k++)
        {
            cin>>x1>>y1;
            a[x1][y1]='*';
        }

        cin>>x>>y;

        if (a[x][y]=='*')
        {
            cout<<"oops!"<<endl<<endl;
        }
        else
        {
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
                {
                    num=0;
                    for (k=1;k<=8;k++)
                    {
                        x1=i+dir[k][0];
                        y1=j+dir[k][1];
                        if (a[x1][y1]=='*')
                        num++;
                    }
                    b[i][j]=num;
                }
            }
            if (b[x][y]>0)
            {
                ans[x][y]=b[x][y]+'0';
            }
            else
            {
                int h=1;int t=1;
                q[h][0]=x;
                q[h][1]=y;
                ans[x][y]=b[x][y]+'0';
                while(t>=h)
                {
                    x=q[h][0];
                    y=q[h][1];
                    h++;
                    int r,c;
                    for (k=1;k<=8;k++)
                    {
                        r=x+dir[k][0];
                        c=y+dir[k][1];
                        if (r>=1&&r<=n&&c>=1&&c<=n&&ans[r][c]=='.')
                        {
                            ans[r][c]=b[r][c]+'0';
                            if (b[r][c]==0)
                            {
                                t++;
                                q[t][0]=r;
                                q[t][1]=c;
                            }
                        }
                    }
                }
            }
            for (i=1;i<=n;i++)
            {
                for (j=1;j<=n;j++)
                    cout<<ans[i][j];
                cout<<endl;
            }
         cout<<endl;
        }
    }
    return 0;
}
