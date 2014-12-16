#include <stdio.h>
#include <stdlib.h>
int main()
{
	long int x;
	scanf ("%d",&x);
	while (x--)
	{
		long int a,s=0;
		scanf ("%ld",&a);
		while (a)
		{
			a=a/5;
			s=s+a;
		}
		printf ("%ld\n",s);
	}
	system("pause");
}
			
