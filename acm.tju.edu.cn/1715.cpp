#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.1415926535897932384626
int main ()
{
	int x,y=0;
	scanf ("%d",&x);
	while (x--)
	{
		y++;
		double R,r;
		int n;
		scanf ("%lf",&R);
		scanf ("%d",&n);
		r=(double)(R*sin(pi/n))/(1+sin(pi/n));
		printf ("Scenario #%d:\n%.3lf\n\n",y,r);
	}
	system("pause");
}
		
		
