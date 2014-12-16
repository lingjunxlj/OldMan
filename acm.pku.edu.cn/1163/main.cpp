#include <iostream>
#include<stdio.h>
using namespace std;
#define maxmm(a,b) (a>b?a:b)
int maxm[102][102],data[102][102];
int main()
{
    int n, i , j, t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++)
                cin>>data[i][j];

        for(i = n-1;i>=0;i--)
            maxm[n-1][i] = data[n-1][i];

        for(i=n-2;i>=0;i--)
            for(j=0;j<=i;j++)
                maxm[i][j]=maxmm(maxm[i+1][j],maxm[i+1][j+1])+data[i][j];
        cout<<maxm[0][0]<<endl;
    }
     return 0;
 }
