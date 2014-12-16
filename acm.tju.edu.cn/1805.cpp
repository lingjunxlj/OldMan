#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int a;
		scanf ("%d",&a);
		int i,b[10];
		int sum=0;
		for (i=0;i<a;i++)
		{			
		    scanf ("%d",&b[i]);
		    sum+=b[i];
		}
		int c;
		c=sum-a+1;
		printf ("%d\n",c);
	}
	system("pause");
}
