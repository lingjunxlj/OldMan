#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
#define V 1005
#define E 15005
int a[E],b[E];
struct Edge
{
    int v1,v2;
    int dis;
}e[E];
int p[V],rank[V];
void Init(int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        p[i]=i;
        rank[i]=1;
    }
}
int getfather(int x)
{
    if(p[x]!=x)p[x]=getfather(p[x]);
    return p[x];
}
void Union(int a,int b)
{
    int ta=getfather(a),tb=getfather(b);
    if(rank[ta]>rank[tb])
    {
        p[tb]=ta;
        rank[ta]+=rank[tb];
    }
    else
    {
        p[ta]=tb;
        rank[tb]+=rank[ta];
    }
}
bool cmp(const Edge &a,const Edge &b)
{
    return a.dis<b.dis;
}
int main()
{
    int i,j,n,m,k,p,max;
    while(cin>>n>>m)
    {
        Init(n);
        k=0;
        for(i=1;i<=m;i++)
        {
            cin>>e[i].v1>>e[i].v2>>e[i].dis;
        }
        sort(e+1,e+m+1,cmp);
        max=0;
        for(i=1;i<=m;i++)
        {
            if(getfather(e[i].v1)==getfather(e[i].v2))
            {
                continue;
            }
            else
            {
                k++;
                if(e[i].dis>max)max=e[i].dis;
                a[k]=e[i].v1;b[k]=e[i].v2;
                Union(e[i].v1,e[i].v2);
            }
        }
        cout<<max<<endl;
        cout<<k<<endl;
        for(i=1;i<=k;i++)
        {
            cout<<a[i]<<" "<<b[i]<<endl;
        }
    }
    
    return 0;
}
