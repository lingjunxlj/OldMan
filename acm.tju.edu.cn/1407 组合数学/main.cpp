#include <iostream>
#include <cstdio>
using namespace std;
double com (double n,double m)
{
	double i;
	double result(1);
	if ( n >= m - n ){ n = m-n; }
	for ( i = m;i >= m-n+1;i-=1 )
	{
		result *= (i / (i - (m - n)));
	}
	return result;
}
int main()
{
	double n,m;
	while (1)
	{
		scanf("%lf%lf",&n,&m);
		if ( n==0 && m==0 ){ break; }
		printf("%.0lf\n",com (n,m+n));
	}
	return 0;
}

