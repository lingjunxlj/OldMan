#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	int x=0;
	while (1)
	{
		x++;
		int a[3],i;
		for (i=0;i<3;i++)
		cin>>a[i];
		if (a[0]==0&&a[1]==0&&a[2]==0)
		break;
		float s;
		if (a[0]==-1)
		{
			if (a[2]*a[2]-a[1]*a[1]<0)
			printf ("Triangle #%d\nImpossible.\n",x);
			else
			{
				s=sqrt(a[2]*a[2]-a[1]*a[1]);
				printf ("Triangle #%d\na = %.3f\n",x,s);
			}
		}
		if (a[1]==-1)
		{
			if (a[2]*a[2]-a[0]*a[0]<0)
			printf ("Triangle #%d\nImpossible.\n",x);
			else
			{
				s=sqrt(a[2]*a[2]-a[0]*a[0]);
				printf ("Triangle #%d\nb = %.3f\n",x,s);
			}
		}
		if (a[2]==-1)
		{
			s=sqrt(a[0]*a[0]+a[1]*a[1]);
			printf ("Triangle #%d\nc = %.3f\n",x,s);
		}
		printf ("\n");
	}
	system("pause");
}
