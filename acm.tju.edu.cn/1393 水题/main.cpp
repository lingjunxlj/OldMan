#include <cmath>
#include <cstdio>
#define Pi 3.141592657
int main()
{
	double D;
	double d;
	double V;
	while(scanf("%lf%lf",&D,&V),D && V)
	{
		d=pow(D*D*D-6*V/Pi,1.0/3);
		printf("%.3lf\n",d);
	}
}

