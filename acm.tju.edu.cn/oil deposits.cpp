#include <iostream>
#include <string>
using namespace std;
const int MAX=200;
char a[MAX][MAX];
bool b[MAX][MAX];
int queue[10003][MAX];
int n,m;
int x[8]={1,1,1,0,0,-1,-1,-1};
int y[8]={1,0,-1,1,-1,1,0,-1};
void BFS(int i,int j)
{
    int k;
    int hx,hy,tx,ty,head=0,tail=1;
    queue[0][0]=i;
    queue[0][1]=j;
    b[i][j]=false;
    while (head<tail)
    {
        hx=queue[head][0];
        hy=queue[head][1];
        head++;
        for (k=0;k<8;k++)
        {           
            tx=hx+x[k];
            ty=hy+y[k];
            if (tx>=0 && tx<=n && ty>=0 && ty<=m && b[tx][ty] && a[tx][ty]=='@')
            {
                queue[tail][0]=tx;
                queue[tail][1]=ty;
                tail++;
                b[tx][ty]=false;
            }
        }
    }
}    
int main()
{
    int i,j;
    while (cin>>n>>m)
    {
        int sum;
        sum=0;
        memset(b,true,sizeof(b));
        if (n==0&&m==0)
        break;
        for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        cin>>a[i][j];
        for (i=0;i<n;i++)
        for (j=0;j<m;j++)
        {
            if (b[i][j]&&a[i][j]=='@')
            {
                sum++;
                BFS(i,j);
            } 
        }
       cout<<sum<<endl;
    }
    
}
        
        
        
