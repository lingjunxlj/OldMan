#include <iostream>
#include<cstdio>
using namespace std; 
#define M 1000 
long long a[M][M];
long long i,j,n;
int main()
{
    
    while (cin>>n)
    {
        if (n<0)
        break;
        for(i=0;i<60;i++)
        for(j=0;j<=i;j++)
        {
            if(i==j||j==0)
            a[i][j]=1;
            else
            a[i][j]=a[i-1][j]+a[i-1][j-1];
            
        }
        for(j=0;j<n;j++)
        printf("%lld ",a[n][j]);
        printf("%lld",a[n][n]);
        printf ("\n");
    }
}
