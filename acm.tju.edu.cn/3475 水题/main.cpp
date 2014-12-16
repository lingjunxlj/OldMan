#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
struct dist
{
    double x;
    double y;
    int num;
}dist[501];
int main()
{
    int n, i, j;
    cin>>n;
    for (i = 1; i <= n; i++)
    {
        cin>>dist[i].x>>dist[i].y;
        dist[i].num = i;
    }
    int num1, num2;
    double Max = 0, temp;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            temp = sqrt( (dist[i].x-dist[j].x)*(dist[i].x-dist[j].x) + (dist[i].y-dist[j].y)*(dist[i].y-dist[j].y) );
            if (temp > Max)
            {
                Max = temp;
                num1 = i;
                num2 = j;
            }
        }
    int sb;
    if (num1 > num2)
    {
        sb = num2;
        num2 = num1;
        num1 =sb;
    }
    cout<<num1<<" "<<num2<<endl;
}
