#include <cstdio>
#include <cstdlib>
#define pi  3.14159265358979323846264338327950288
int main()
{
    double r,O,H;
    scanf ("%lf",&r);
    O=pi*r*r;
    H=2*r*r;
    printf("%.6lf\n%.6lf\n",O,H);
    system("pause");
}
