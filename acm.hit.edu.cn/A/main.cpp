#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define Inf (0x7fffffff)
#define ECS (1E-6)
#define MAXN 100001
int n, m;
double a[MAXN], s[MAXN], gl, gr;
int cnt;
bool check(double v)
{
    int i=m;
    double b=s[m-1]-m*v;
    double s1,s2;
    for(i=m; i<n; i++)
    {
        s1=b+a[i]-v;
        s2=s[i]-s[i-m]-m*v;
        b=max(s1,s2);
        if(b>=ECS)
        return true;
    }
    return (b>=ECS);
}

double solve()
{
    double l=gl,r=gr,mid=0;
    while(r-l>ECS)
    {
        mid =(l+r)/2.0;
        check(mid)?l=mid:r=mid;
    }
    return l;
}
int main()
{
    scanf("%d%d",&n,&m);
    gl=Inf;
    gr=-Inf;
    int i;
    for(i=0;i<n; i++)
    {
        scanf("%lf",&a[i]);
        a[i]*=1000.0;
        if(a[i]<gl)
        gl=a[i];
        if(a[i]>gr)
        gr=a[i];
    }
    s[0]=a[0];
    for(i=1;i<n;i++)
    s[i]=s[i-1]+a[i];
    cnt=solve()+0.3;
    printf("%d\n", cnt);
    return 0;
}
