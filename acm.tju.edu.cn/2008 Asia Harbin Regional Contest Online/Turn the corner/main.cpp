#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
#define pi 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128
int main()
{
    bool fg;
    double X, Y, L, D, x;
    while (scanf("%lf %lf %lf %lf", &X, &Y, &L, &D) != EOF)
    {
        double t;
        fg = 1;
        //printf("%lf----pi\n", pi);
        for (double i = 0; i < 91; i += 0.01)
        {
            t = i*pi/180.0;

            x = (X/tan(t) - L * sin(t)/tan(t) - D/cos(t)/tan(t) );
            //printf("%lf----x\n", x);
            if (-x >= Y)
            {
                fg = 0;
                break;
            }
        }
        if (fg)
            printf("yes\n");
        else
            printf("no\n");
    }
}
