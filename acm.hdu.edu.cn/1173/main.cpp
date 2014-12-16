#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct node
{
    double x;
    double y;
}point[1000001];
int cmp(const node a, const node b)
{
    return a.x < b. x;
}
int cmp1(const node a, const node b)
{
    return a.y < b. y;
}
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for(int i = 0; i < n; i++)
            scanf("%lf %lf", &point[i].x, &point[i].y);
        double temp_x, temp_y;
        if(n%2 == 1)
        {
            sort(point, point+n,cmp);
            temp_x = point[(n - 1) / 2].x;

            sort(point, point+n,cmp1);
            temp_y = point[(n - 1) / 2].y;
        }
        else
        {
            sort(point, point+n,cmp);
            temp_x = (point[n / 2 - 1].x + point[n / 2].x)/2;

            sort(point, point+n,cmp1);
            temp_y = (point[n / 2 - 1].y + point[n / 2].y)/2;
        }
        printf("%.2lf %.2lf\n", temp_x, temp_y);

    }

}
