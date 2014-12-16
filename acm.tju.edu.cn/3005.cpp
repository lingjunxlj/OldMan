#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int x,y=0;
	scanf ("%d",&x);
	while (x--)
	{
		y++;
		double a;
		char b[100];
		scanf ("%lf",&a);
		scanf ("%s",b);
		
		if (b[0]=='k'&&b[1]=='g')
		{
			a=a*2.2046;
			printf ("%d %.4lf lb",y,a);
		}
		if (b[0]=='l'&&b[1]=='b')
		{
			a=a*0.4536;
			printf ("%d %.4lf kg",y,a);
		}
		if (b[0]=='l'&&b[1]!='b')
		{
			a=a*0.2642;
			printf ("%d %.4lf g",y,a);
		}
		if (b[0]=='g')
		{
			a=a*3.7854;
			printf ("%d %.4lf l",y,a);
		}
		printf ("\n");
		
	}
	system("pause");
}
		
		
		
		
		
