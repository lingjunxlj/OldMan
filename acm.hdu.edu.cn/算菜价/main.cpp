#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
char str[1200];
double num, price;
int main()
{
    double sum = 0;
    while(scanf("%s %lf %lf", str, &num, &price) != EOF)
    {
        sum += num * price;
    }
    printf("%.1lf\n", floor(sum*10+0.5)/10);
}
