#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    double a, b, c;
    double sha, shan;
    while(cin>>a>>b>>c)
    {


        sha = double(b + c)/(a + b+ c+ c);
        shan = (1 - sha);

        double ans = a * sha * sha + b * shan * shan - 2*c * sha*shan;
        printf("%.6lf\n", ans);

    }
}
