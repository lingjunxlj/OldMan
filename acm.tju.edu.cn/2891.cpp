#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int n;
	scanf ("%d",&n);
	while (n--)
	{
		int x;
		scanf("%d",&x);
		int a[x];
		int i,j=0;
		for (i=0;i<x;i++)
		scanf ("%d",&a[i]);
		int k;
		k=x-1;
		while(k--)
		{
			for (i=0;i<=(x-j);i++)
			a[i]=a[i+1]-a[i];
			j++;			
			if (k==0)
			break;
		}
	     printf ("%d\n",a[0]);
	}
	system("pause");
}
