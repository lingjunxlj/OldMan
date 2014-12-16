#include <cstdio>
#include <cmath>
int main()
{
	double x;
	while (scanf ("%lf",&x))
	{
		if (x<0)
		break;
		double temp;
		temp=sqrtl(2*x);
		printf("%.2lf\n",temp);
	}
	while (1);
}
