#include <stdio.h>
#include <stdlib.h>
int main ()
{
	while (1)
	{
		int m,n;
		scanf ("%d",&n);
		if (n==0)
		break;
		scanf ("%d",&m);
		if (n%(m+1) != 0)
		printf ("Just Do It.\n");
		else
		printf  ("Think About It.\n");
	}
	system("pause");
}
		
		
		
		
		
		
		
		
		
		
