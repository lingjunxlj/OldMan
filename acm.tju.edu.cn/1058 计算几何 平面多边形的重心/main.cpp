#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int x0, y0, x1, y1, x2, y2;
        cin>>x0>>y0;
        cin>>x1>>y1;
        int i;
        double sum_area = 0, sum_x = 0, sum_y = 0;
        for (i = 2; i < n; i++)
        {
            cin>>x2>>y2;
            int X, Y;
            X = x0 + x1 +x2;
            Y = y0 + y1 +y2;
            double s;
            s = (x0 * y1 - y0 *x1 + x1 * y2 - y1 *x2 + x2 * y0 - y2 *x0);
            sum_area += s;
            sum_x += s*X;
            sum_y += s*Y;
            x1 = x2;
            y1 = y2;
        }
        printf ("%.2lf %.2lf\n",sum_x/sum_area/3, sum_y/sum_area/3);
    }
}
