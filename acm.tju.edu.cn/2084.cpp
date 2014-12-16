#include <stdio.h>
#include <stdlib.h>
#define pi 3.1415927
int main()
{
	int b;
	float a,c;
	int i=0;
	while (1)
	{
		i++;
		scanf("%f",&a);
		scanf("%d",&b);
		scanf("%f",&c);
		if (b==0)
		break;
		float s,chang,mph;
		s=pi*a;
		chang=(float)b*s/(5280*12);
		mph=chang/(c/3600);
		printf ("Trip #%d: %.2f %.2f\n",i,chang,mph);
	}
	system("pause");
}
		
		
