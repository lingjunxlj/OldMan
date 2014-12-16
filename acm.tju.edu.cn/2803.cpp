#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int y;
	scanf ("%d",&y);
	while(y--)
	{
		float a,b,c;
		scanf ("%f",&a);
		scanf ("%f",&b);
		scanf ("%f",&c);
		if ((b*b-(4*a*c))<0)
		printf ("No solution!\n");
		else
		{
		float x;
		x=sqrt(b*b-4*a*c);
		float m,n;
		m=(-b+x)/(2*a);
		n=(-b-x)/(2*a);
		if ((b*b-(4*a*c))==0)
		printf ("%.3f\n",n);
		else
		printf ("%.3f %.3f\n",n,m);
	    }
	}
	system("pause");
}
