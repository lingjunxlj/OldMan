#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void PrintStation(int l[][6],int i,int j,int n)
{
    if(j>=1)
    {
        PrintStation(l,l[i-1][j-1],j-1,n);
        printf("line:%d station:%d \n",i,j);
    }
}

void FastestWay(int a[][6],int t[][5],int e[],int x[],int n)
{
    int f[2][6];
    int l[2][6];
    int ff;
    int ll;

    f[0][0]=e[0]+a[0][0];
    f[1][0]=e[1]+a[1][0];

    for(int j=1;j<n;j++)
    {
        if(f[0][j-1]+a[0][j]<f[1][j-1]+t[1][j-1]+a[0][j])
        {
            f[0][j]=f[0][j-1]+a[0][j];
            l[0][j]=1;
        }
        else
        {
            f[0][j]=f[1][j-1]+t[1][j-1]+a[0][j];
            l[0][j]=2;
        }
        if(f[1][j-1]+a[1][j]<f[0][j-1]+t[0][j-1]+a[1][j])
        {
            f[1][j]=f[1][j-1]+a[1][j];
            l[1][j]=2;
        }
        else
        {
            f[1][j]=f[0][j-1]+t[0][j-1]+a[1][j];
            l[1][j]=1;
        }
    }

    if(f[0][n-1]<=f[1][n-1])
    {
        ff=f[0][n-1]+x[0];
        ll=1;
    }
    else
    {
        ff=f[1][n-1]+x[1];
        ll=2;
    }

    PrintStation(l,ll,6,n);
}
int a[2][124760];
int t[2][124760];
int main()
{
    int a[2][6]={{7,9,3,4,8,4},{8,5,6,4,5,7}};
    int t[2][5]={{2,3,1,3,4},{2,1,2,2,1}};
    int e[2]={0,0};
    int x[2]={0,0};
    int n, m;

    while (cin>>n>>m)
    {
        memset(t, 0, sizeof(t));
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < m; j++)
                cin>>a[i][j];
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin>>x>>y>>z;

        }

        FastestWay(a,t,e,x,n);
    }



    return 0;
}
