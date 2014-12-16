#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 1000003

int a[MAX][2],t,n;
int GetMax(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
    int i,j;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(i=1;i<=2;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&a[j][i]);
        for(j=n-1;j>=1;j--)
            for(i=2;i>=1;i--)
            {
                if(i==2)
                    a[j][2]=GetMax(a[j+1][1],a[j+1][2]+a[j][2]);
                 if(i==1)
                    a[j][1]=GetMax(a[j+1][2],a[j+1][1]+a[j][1]);
            }
        int MM=-1;
        if(a[1][1]>MM)
            MM=a[1][1];
        if(a[1][2]>MM)
            MM=a[1][2];
        printf("%d\n",MM);
    }
    return 0;
}
