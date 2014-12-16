#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct node
{
    int a;
    int b;
    int c;
}Point[10001];
int n;
double mid, mid2, res1, res2;
double f(double x)
{
    double ans, Max = Point[0].a * x * x + Point[0].b * x + Point[0].c;;
    for (int i = 1; i < n; i++)
    {

        ans = Point[i].a * x * x + Point[i].b * x + Point[i].c;

        if (Max < ans)
            Max = ans;
    }
    return Max;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d %d", &Point[i].a, &Point[i].b, &Point[i].c);

        double l = 0.0, r = 1000.0;
        do
        {
            mid = (l + r) / 2;
            mid2 = (mid + r) / 2;

            res1 = f(mid);
            res2 = f(mid2);
            //printf(" %0.4lf %0.4lf  %0.4lf %0.4lf \n",res1,res2,mid,mid2);
            if (res1 > res2)
                l = mid;
            else
                r = mid2;

        }while(fabs(res1 - res2) > 1e-8);
        printf("%.4lf\n", res1);
    }
}
