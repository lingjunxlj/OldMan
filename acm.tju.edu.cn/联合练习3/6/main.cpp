#include <iostream>
#include <algorithm>
#include <cstdio>
#include <math.h>
#define esp 1e-8
using namespace std;

struct point
{
    double x,y;
};

struct line
{
    double a,b,c;
};

int dblcmp(double d)
{
    if(fabs(d)<esp)
        return 0;
    return (d>0)?1:-1;
}

double det(double x1, double y1, double x2, double y2)
{
    return x1*y2 - y1*x2;
}

double cross(point a, point b, point c)
{
    return det(b.x-a.x, b.y-a.y, c.x-a.x, c.y-a.y);
}

void lineintersect(line l1,line l2, double &x, double &y)
{
    double d=l1.a*l2.b-l2.a*l1.b;
    x=(l2.c*l1.b-l1.c*l2.b)/d;
    y=(l2.a*l1.c-l1.a*l2.c)/d;
}

void lineform(double x1,double y1,double x2,double y2, line &temp)//ax+by+c=0;
{
     temp.a=y2-y1;
     temp.b=x1-x2;
     temp.c=x2*y1-x1*y2;
}
point a[50000],b[50000],c,d;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,ans=0;
        double ex,ey;
        scanf("%lf%lf",&ex, &ey);


        for (i=1;i<=n;i++)
        scanf("%lf%lf%lf%lf",&a[i].x, &a[i].y, &b[i].x, &b[i].y);

        for (i=1;i<=n;i++)
        for (j=i+1;j<=n;j++)
        {

            if (a[i].x==b[j].x)
            continue;

            {
                line l1,l2;
                double xx,yy;
                lineform(a[i].x, a[i].y, b[i].x, b[i].y, l1);
                lineform(a[j].x, a[j].y, b[j].x, b[j].y, l2);
                lineintersect(l1,l2,xx,yy);
                if (xx>ex&&xx<ey)
                ans++;

            }
        }

        printf("%d\n",ans);

     }
    return 0;
}
