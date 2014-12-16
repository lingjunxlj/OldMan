#include <iostream>
#include <cstdio>
#include <cmath>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MN 50005
using namespace std;
int mi[MN][17],mx[MN][17],w[MN];
int n,q;
void rmqinit()
{
    int i,j,m;
    for(i=1; i<=n; i++)
    {
        mi[i][0]=mx[i][0]=w[i];
    }
    m=floor(log((double)n)/log(2.0));
    for(i=1; i<=m; i++)
    {
        for(j=n; j>=1; j--)
        {
            mx[j][i]=mx[j][i-1];
            if(j+(1<<(i-1))<=n)mx[j][i]=max(mx[j][i],mx[j+(1<<(i-1))][i-1]);
            mi[j][i]=mi[j][i-1];
            if(j+(1<<(i-1)<=n))mi[j][i]=min(mi[j][i],mi[j+(1<<(i-1))][i-1]);
        }
    }
}
int rmqmin(int l,int r)
{
    int m=floor(log((double)(r-l+1))/log(2.0));
    return min(mi[l][m],mi[r-(1<<m)+1][m]);
}
int rmqmax(int l,int r)
{
    int m=floor(log((double)(r-l+1))/log(2.0));
    return max(mx[l][m],mx[r-(1<<m)+1][m]);
}
int main()
{
    cin>>n>>q;
    for(int i=1; i<=n; i++)
        scanf("%d",&w[i]);
    rmqinit();
    int l,r;
    for(int i=1; i<=q; i++)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",rmqmax(l,r)-rmqmin(l,r));
    }
    return 0;
}
