#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	float a[12];
	int i;
	float sum=0;
	for (i=0;i<12;i++)
	{
		scanf ("%f",&a[i]);
		sum+=a[i];
	}
	float s;
	s=sum/12.0;
	printf ("$%.2f\n",s);
	system("pause");
}
