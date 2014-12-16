#include<cstdio>
#include<cmath>
int main()
{
    int m, i;
    double d, v, u;
    scanf("%d", &m);
    for(i = 1; i <= m; i++)
    {
        scanf("%lf %lf %lf", &d, &v, &u);
        printf("Case %d: ", i);
        if(u > v && v)
        printf("%.3lf\n", d/sqrt(u * u - v * v) - d / u);
        else
        printf("can't determine\n", i);
    }
}
