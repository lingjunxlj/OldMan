//算法导论 p591 最近点对变形
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
double ans;
struct node
{
    double x;
    double y;
}point[20020], point_mid[20020];
double dist(node a, node b)
{
    return sqrt( (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) );
}
double min(double x, double y)
{
    return x < y? x:y;
}
bool cmpx(node a, node b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
bool cmpy(node a, node b)
{
    if (a.y != b.y)
        return a.y < b.y;
    return a.x < b.x;
}
void merge(int l, int r)
{
   int mid;
   double temp;
   if (r - l + 1<= 6) //对于小于6个点的情况进行枚举
   {
       for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++)
            {
                temp = dist(point[i], point[j]);
                if (temp < ans/2) //初步筛选
                    for (int k = j + 1; k <= r; k++)
                        ans = min(ans, temp + dist(point[i], point[k]) + dist(point[j], point[k]) );
            }
        return;
   }

    mid = (l + r)/2 - 1;
    merge(l, mid);
    merge(mid + 1, r);

    int head = 0;
    for (int i = l; i <= r; i++)
        if ( (point[mid].x - point[i].y) > 0? (point[mid].x - point[i].y) : (point[i].y - point[mid].x) < ans/2)
            point_mid[head++] = point[i];

    sort(point_mid, point_mid + head, cmpy);
    for (int i = 0; i < head; i++)
        for (int j = i + 1; j < head && j <= i + 7; j++) //只需检查之后7个点
        {
            temp = dist(point_mid[i], point_mid[j]);
            if (temp < ans/2)
                for (int k = j + 1; k < head && k <= i + 7; k++)
                    ans = min(ans, temp + dist(point_mid[i], point_mid[k]) + dist(point_mid[j], point_mid[k]) );
        }
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &point[i].x, &point[i].y);

        sort(point, point + n, cmpx);
        ans = 0x7fff;
        merge(0, n-1);
        printf("%.3lf\n", ans);
    }
}
