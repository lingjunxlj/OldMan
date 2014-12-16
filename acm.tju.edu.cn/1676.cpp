#include <iostream>
using namespace std;
const int inf=0x7f;
const int MAX=150;
int map[MAX][MAX],lowcast[MAX],close[MAX];
bool flag[MAX];
int prim(int n)
{
    
    int i,j,min,u,sum=0;
    for (i=1;i<n;i++)
    {
        lowcast[i]=map[0][i];
        close[i]=1;
    }
    for (i=0;i<n-1;i++)
    {
        min=inf;
        u=0;
        for (j=1;j<n;j++)
        {
            if (!flag[j]&&min>lowcast[j])
            {
                min=lowcast[j];
                u=j;
            }
        }
        flag[u]=true;
        for (j=1;j<n;j++)
        {
            if (!flag[j]&&lowcast[j]>map[u][j])
            {
                lowcast[j]=map[u][j];
                close[j]=u;
            }
        }
    }
    for (i=0;i<n;i++)
    sum+=map[i][close[i]];
    return sum;
}
int main()
{
    int n,m;
    while (1)
    {
        memset(map,inf,sizeof (map));
        memset(flag,false,sizeof (flag));
        cin>>n;
        if (n==0)
        break;
        int i,j,a,b,c;
        cin>>m;
        if (m==0)
        cout<<0<<endl;
        if (m!=0)
        {
            for (i=0;i<m;i++)
            {
                cin>>a>>b>>c;
                map[a-1][b-1]=map[b-1][a-1]=c;
            }
            cout<<prim(n)<<endl;
        }   
    }
}
        
        
            
            
            
        
