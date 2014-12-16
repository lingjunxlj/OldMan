#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int a[10],b[10],s;
		int i;
		scanf ("%d",&s);
		for (i=0;i<s;i++)
		scanf ("%d",&a[i]);
		for (i=0;i<s;i++)
		scanf ("%d",&b[i]);
		int sum=0;
		for (i=0;i<s;i++) 
		sum+=a[i]*b[i];
		printf ("%d\n",sum);
	}
	system("pause");
}
