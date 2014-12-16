#include <iostream>
using namespace std;
#define MAX 102
const int inf=9999;
int map[MAX][MAX];
int lowcast[MAX];
bool flag[MAX];
int Prim(int n)
{
    int i,j,min,u,sum;
    sum=0;
    for (i=1;i<n;i++)
    lowcast[i]=map[0][i];
    for (i=0;i<n-1;i++)
    {
        min=inf;
        j=0;
        for (j=1;j<n;j++)
        {
            if (!flag[j]&&min>lowcast[j])
            {
                min=lowcast[j];
                u=j;
            }
        }    
        sum+=min;
        flag[u]=true;
        for (j=1;j<n;j++)
        {
            if (!flag[j]&&map[u][j]<lowcast[j])
            lowcast[j]=map[u][j];
        }
    }
    return sum;
}
int main()
{
    char ch;
    int i,j,k,n,start,end; 
    while (cin>>n)
    {
        if (n==0)
        break;
        memset(flag,false,sizeof(flag));
        memset(map,0x7f,sizeof(map)); 
        for(i=0;i<n-1;i++)
        {
            cin>>ch>>k;
            start = (int)ch - 65;
            for(j=0;j<k;j++)
            {
                cin>>ch;
                end = (int)ch - 65;
                cin>>map[start][end];
                map[end][start] = map[start][end];
            }
        }
          
        cout<<Prim(n)<<endl;  
    }
}
            
