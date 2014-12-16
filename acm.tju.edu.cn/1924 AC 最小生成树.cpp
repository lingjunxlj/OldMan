#include<iostream>
#include<string.h>
using namespace std;
#define MAXSIZE 26
#define MAXVALUE 101
int g[MAXSIZE][MAXSIZE];
int lowcost[MAXSIZE],s[MAXSIZE];
int prim(int n)
{
    int i,j,k,min,mincost;
    s[0] = 1;
    mincost = 0;
    for(i=1;i<n;i++)
    lowcost[i] = g[0][i];
    for(i=0;i<n-1;i++)
    {
        min = MAXVALUE;
        j = 0;
        for(k=1;k<n;k++)
        {
            if(!s[k] && lowcost[k]<min)
            {
                min = lowcost[k];
                j = k;
            }
        }
        mincost += min;
        s[j] = 1;
        for(k=1;k<n;k++)
            if(!s[k] && g[j][k]<lowcost[k])
                lowcost[k] = g[j][k];
    }
    return mincost;
}
int main()
{
    int i,j,k,n,start,end;
    char ch;
    while(cin>>n)
    {
        if(n==0) break;

        memset(s,0,sizeof(s));
        memset(g,MAXVALUE,sizeof(g));
        for(i=0;i<n-1;i++)
        {
            cin>>ch>>k;
            start = (int)ch - 65;
            for(j=0;j<k;j++)
            {
                cin>>ch;
                end = (int)ch - 65;
                cin>>g[start][end];
                g[end][start] = g[start][end];
            }

        }    
        cout<<prim(n)<<endl;
    }
    return 0;
}
