#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int n;
		scanf ("%d",&n);
		int q=n,a[100]={},i=0;
		while (q!=0)
		{
			a[i]=q%2;
			q=q/2;
			i++;
		}

		int j;
		for (j=0;j<i-1;j++)
		{
			if (a[j]==1)
			printf ("%d ",j);
		}
		if (a[i-1]==1)
		printf ("%d",i-1);
		printf ("\n");
	}
	system("pause");
}
		
			
