#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
double num[1200];
char tmp[1200];
int main()
{
    int n;
    while(cin>>n, n)
    {
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>num[i];
            sum += num[i];
        }
        double arr = sum/n ;
        //printf("arr %lf\n", arr);
        sprintf(tmp, "%.2lf", arr);
        sscanf(tmp, "%lf", &arr);
        double ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (num[i] - arr > 0)
                ans1 += (num[i] - arr);
            if (num[i] - arr < 0)
                ans2 += -(num[i] - arr);
        }
        if (ans1 > ans2)
            printf("$%.2lf\n", ans2);
        else
            printf("$%.2lf\n", ans1);
    }
}
