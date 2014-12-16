#include<stdlib.h>
#include<string.h>
#include<iostream>
using namespace std;
int ca,i,a,b;
long long f[100];
int main()
{
    scanf("%d", &ca);
    memset(f,0,sizeof(f));
    f[0]=1;
    f[1]=1;f[2]=2;
    for(i=3;i<=100;i++)
        f[i]=f[i-1]+f[i-2];
    while(ca--)
    {
        scanf("%d %d",&a,&b);
        printf("%I64d\n",f[b-a]);
    }
    return 0;
}
