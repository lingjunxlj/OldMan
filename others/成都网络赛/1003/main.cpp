#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define pa printf("pass\n");
#define exp 1e-8
#define pi 3.1415926535897932384

int n;
double len[105];

double init(double a)
{
    double ans = a*a*n/(4*tan((double)(pi/n)));
    //cout<<ans<<endl;
    //cout<<"tan = "<<tan((double)(pi/n))<<endl;
    return ans;

}

double hailun(double a, double b, double c)
{
    double p = (a+b+c)/2;
    double ans = sqrt(p*(p-a)*(p-b)*(p-c));
    return ans;
}

double solve(double a)
{
    double sum = 0;
    int i;
    for(i=0; i<n-1; ++i)
    {
        sum += hailun(a, len[i], len[i+1]);
    }
    sum += hailun(a, len[0], len[n-1]);
    return sum;
}

double Ta(double a)
{
    return init(a)-solve(a);
}
double num1[1001];
int main()
{
    int t, i, k, x = 1;
    scanf("%d",&t);
    for(k=1; k<=t; k++)
    {
        scanf("%d",&n);
        for(i=0; i<n; i++)
        {
            scanf("%lf",&len[i]);

        }
        int Max = 0;
        int Min = 0x7fff;
        for(i=0; i<n - 1; i++)
        {
            if (Max < abs(len[i] - len[i + 1]))
                Max = abs(len[i] - len[i + 1]);
            if (Min > abs(len[i] + len[i + 1]))
                Min = abs(len[i] + len[i + 1]);

        }
        if (Max < abs(len[0] - len[n - 1]))
            Max = abs(len[0] - len[n - 1]);
        if (Min > len[0] + len[n - 1])
            Min = len[0] + len[n - 1];
        double r= Min, l = Max;
        double rp = r;
        double lp = l;
        double mid = 0.0, result1 = 0, result2 = 0;
        int sum = 0;
        do
        {
            sum ++;
            mid = (l + r)/2;
            result1 = init(mid);
           //printf("1 %lf\n", result1);
            result2 = solve(mid);
            //printf("2 %lf\n", result2);
            if (result1-result2 > 1e-10)
                r = mid;
            else
                l = mid;
            if (sum == 70000)
                break;
        }while(fabs(result1-result2) > 1e-10);
        printf("Case %d: ", x++);
        if (sum == 70000)
            printf("impossible");
        else
        printf("%0.3lf\n",r);
    }
    return 0;
}
