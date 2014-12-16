#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n;
int v[3000];
int sum;
int va;
int f[3000];
int a,b,d,e,c,k;
int main()
{
    while(scanf("%d",&n),n)
    {
        for(a=0;a<3000;a++)
            f[a]=0;

        for(a=0;a<n;a++)
        {
            scanf("%d",&v[a]);

        }
        scanf("%d",&k);
        if(k<5)
        {
            printf("%d\n",k);
            continue;
        }
        sort(v,v+n);
        sum=k-5;
        for(a=0;a<n-1;a++)
            for(b=sum;b>=v[a];b--)
                f[b]=f[b]>f[b-v[a]]+v[a]?f[b]:f[b-v[a]]+v[a];
        printf("%d\n",k-(f[sum]+v[n-1]));



    }return 0;
}
