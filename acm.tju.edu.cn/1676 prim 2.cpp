#include<iostream>
using namespace std;
int c[60][60];
int close[60];
int lowcost[60];
int  prim(int n , int c[60][60])
{ 
    bool s[60];
    s[1]=true;
    int i,j,k;
    close[1]=0;
    lowcost[1]=0;
    for (i=2;i<=n;i++)
    {
        lowcost[i]=c[1][i];
        close[i]=1;
        s[i]=false;
    }
    for (i=1;i<n;i++)
    {
        int min=100000;
        j=1;
        for (k=2;k<=n;k++)
        if ((lowcost[k]<min)&&!s[k])
        {
              min=lowcost[k];
              j=k;
        }     
        s[j]=true;
        for (k=2;k<=n;k++)
        {
            if ((c[j][k]<lowcost[k])&&!s[k]) 
            {
                lowcost[k]=c[j][k];
                close[k]=j;
            }
        }
    }
    int sum=0;
    for (i=1;i<=n;i++)
    {
        sum+=c[i][close[i]];
    }
    return sum; 
}
int main()
{
    int p, n ;
    int i,j;
    while(cin>>p)
    {
        if (p) cin>>n;
        else break;
        for (i=1;i<=p;i++)
        for (j=1;j<=p;j++)
        c[i][j]=10000;
        int x,y,len;
        for (i=1;i<=n;i++)
        {
            cin>>x>>y>>len;
            if (c[x][y]==0)
            {
                c[y][x]=len;
                c[x][y]=len;
            }
            else if (len<c[x][y])
            {
                c[y][x]=len;
                c[x][y]=len;
            }    
        }
        int sum=prim(p, c);
        cout<<sum<<endl;
    }
    return 0;
}
