#include <cstdio>
#include <cmath>
int main()
{
    int n;
    double h1, r1, x1, y1, z1, h2, r2, x2, y2, z2, x3, y3, z3, w1, w2, d1, d2;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%lf %lf %lf %lf %lf", &h1, &r1, &x1, &y1, &z1);
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &h2, &r2, &x2, &y2, &z2, &x3, &y3, &z3);
        h2 = 0.9*h2;
        z1 += h1 - r1;
        z2 += h2 - r2;
        d1 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
        w1 = asin(r1*1.0/d1);
        d2 = ((x1-x2)*x3+(y1-y2)*y3+(z1-z2)*z3)/d1/sqrt(x3*x3+y3*y3+z3*z3);
        w2 = acos(d2);

        if(w1 >= w2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
