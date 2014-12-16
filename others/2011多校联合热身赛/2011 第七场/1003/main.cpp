#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const double ep	= 1e-8;
//求多边形重心
struct point
{
    double x,y;
}a[20001];
int n;
int comp(point a,point b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double disptoline(point p,point p1,point p2)
{
    return fabs(xmult(p,p1,p2)/dis(p1,p2));
}
point bcenter(point pnt[], int n)
{
    point p, s;
    double tp, area = 0, tpx = 0, tpy = 0;
    p.x = pnt[0].x; p.y = pnt[0].y;
    for (int i = 1; i <= n; ++i)
    {
        s.x = pnt[(i == n) ? 0 : i].x;
        s.y = pnt[(i == n) ? 0 : i].y;
        tp = (p.x * s.y - s.x * p.y);
        area += tp / 2;
        tpx += (p.x + s.x) * tp;
        tpy += (p.y + s.y) * tp;
        p.x = s.x; p.y = s.y;

    }
 s.x = tpx / (6 * area);
 s.y = tpy / (6 * area);
 return s;
}
// 根据已知两点p1,p2坐标，求过这两点的直线解析方程： a*x+b*y+c=0 (a>=0)
point symmetry(point p1,point p2,point p)
{
    point temp;
    int sign=1;
    double a,b,c;
    a=p2.y-p1.y;
    if(a<0)
    {
        sign=-1;
        a=sign*a;
    }
    b=sign*(p1.x-p2.x);
    c=sign*(p1.y*p2.x-p1.x*p2.y);
    temp.x=((b*b-a*a)*p.x-2*a*b*p.y-2*a*c)/(a*a+b*b);
    temp.y=((a*a-b*b)*p.y-2*a*b*p.x-2*b*c)/(a*a+b*b);
    return temp;
}
int binsearch(point temp)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(fabs(a[mid].x-temp.x)<eps && fabs(a[mid].y-temp.y)<eps)
            return mid;
        else if(fabs(a[mid].x-temp.x)<eps && a[mid].y-temp.y<eps)
            low=mid+1;
        else if(fabs(a[mid].x-temp.x)<eps && a[mid].y-temp.y>eps)
            high=mid-1;
        else if(a[mid].x-temp.x<eps)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
int judge(point center,point temp)
{
    int i,is[20001],pos=-1;
    memset(is,0,sizeof(is));
    point temp2;
    for(i=0;i<n;i++)
    {
        temp2=symmetry(center,temp,a[i]);
        pos=binsearch(temp2);
        if(pos>=0)
            is[pos]=1;
    }
    for(i=0;i<n;i++)
        if(is[i]==0)
            return false;
    return true;
}
void solve()
{
    int i,j,flag,is[20001];
    point center,temp;
    center=bcenter(a,n);
    sort(a,a+n,comp);
    temp.x=center.x,temp.y=center.y+1;
    flag=judge(center,temp);
    if(flag)
    {
        puts("YES");
        return ;
    }
    temp.x=center.x+1;
    temp.y=center.y;
    flag=judge(center,temp);
    if(flag)
    {
        puts("YES");
        return ;
    }
    temp.x=center.x+1,temp.y=center.y+1;
    flag=judge(center,temp);
    if(flag)
    {
        puts("YES");
        return ;
    }
    temp.x=center.x+1;
    temp.y=center.y-1;
    flag=judge(center,temp);
    if(flag)
    {
        puts("YES");
        return ;
    }
    puts("NO");
}
int main()
{
    int t=10,T=1,i;

    while(~scanf("%d",&n))
    {

        for(i=0;i<n;i++)
            scanf("%lf%lf",&a[i].x,&a[i].y);
        solve();

    }
    return 0;
}
