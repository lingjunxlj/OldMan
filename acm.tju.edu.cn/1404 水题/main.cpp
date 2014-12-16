#include <cstdio>
struct Point
{
    double x,y;
}p[1001];

int main()
{
    int n, i;
    while(scanf("%d", &n) != EOF)
    {
        for(i = 1;i <= n; i ++)
        scanf("%lf %lf", &p[i].x, &p[i].y);

        printf("%d", n);
        for(i = 1; i < n; i ++)
        printf(" %lf %lf", (p[i].x+p[i+1].x)/2, (p[i].y+p[i+1].y)/2);

        printf(" %lf %lf\n",(p[n].x+p[1].x)/2, (p[n].y+p[1].y)/2);
    }
}
