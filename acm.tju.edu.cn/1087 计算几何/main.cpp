#include<cmath>
#include<iostream>
#include<cstdio>
using namespace std;
const double PI = acos(-1.0);
int main()
{
    double x, y, z, role, half, maxn;
    double R, r, c, area;
    int t = 0;
    while(scanf("%lf%lf%lf%lf",&x,&y,&z,&role))
    {
        if(x+y+z+role==0)
            break;
        t++;
        c = x + y + z;
        half = c * 0.5;
        area = sqrt(half * (half - x) * (half - y) * (half - z));
        R = area * 2.0 / c;

        if(x + y + z <= role)
            maxn = area;

        else if(2.0 * PI * R >= role)
            maxn = role * role / (4.0 * PI);

        else
        {
            r = (c - role) / (c / R - 2.0 * PI);
            maxn = area + PI * r * r - (r * r * area / (R * R));
        }
        printf("Case %d: %.2lf\n", t, maxn);
    }
    return 0;
}
