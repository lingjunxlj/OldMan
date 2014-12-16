#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int x, n;
	scanf ("%d",&x);
	while (x--)
	{
	
	scanf ("%d",&n);
	if (n%2==0)
	n=n/2*(n/2-1);
	else
	{
		n++;
		n=n/2*(n/2-1)-(n/2-1);
	}
	printf ("%d\n",n);
}
system ("pause");
}
