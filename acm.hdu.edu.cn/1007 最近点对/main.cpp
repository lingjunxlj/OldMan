#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

const int N=200002;
const double EPS=1e-10;
const double INF=1e20;

struct Point
{
    double x,y;
}
p[N];
int n,o[N],on;

inline double dis(const Point & a,const Point & b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline int dcmp(double a,double b)
{
    if(a-b<EPS && b-a<EPS)
  return 0;
    if(a>b)
  return 1;
    return -1;
}

inline bool cmp_x(const Point & a,const Point & b)
{
    return dcmp(a.x,b.x)<0;
}

inline bool cmp_y(const int & a,const int & b)
{
    return dcmp(p[a].y,p[b].y)<0;
}

inline double min(double a,double b)
{
    return a<b ? a : b;
}

double search(int s,int t)
{
    int mid=(s+t)>>1,i,j;

    double ret=INF;

    if(s>=t)
  return ret;

 for(i=mid;i>=s && ! dcmp(p[i].x,p[mid].x);--i);
  ret=search(s,i);

 for(i=mid;i<=t && ! dcmp(p[i].x,p[mid].x);++i);
  ret=min(ret,search(i,t));

    on=0;
 for(i=mid;i>=s && dcmp(p[mid].x-p[i].x,ret)<=0;--i)
  o[++on]=i;

    for(i=mid+1;i<=t && dcmp(p[i].x-p[mid].x,ret)<=0;++i)
  o[++on]=i;

    sort(o+1,o+on+1,cmp_y);

 for(i=1;i<=on;++i)
    {
        for(j=1;j<=10;++j)
        {
            if(i+j<=on)
    ret=min(ret,dis(p[o[i]],p[o[i+j]]));
        }
    }
    return ret;
}

int main()
{
    while(scanf("%d",&n)-EOF && n!=0)
    {
        for(int i=1;i<=n;++i)
   scanf("%lf%lf",&p[i].x,&p[i].y);
  sort(p+1,p+n+1,cmp_x);
  double sum=search(1,n);
  printf("%.2lf\n",sum/2);
 }
    return 0;
}
