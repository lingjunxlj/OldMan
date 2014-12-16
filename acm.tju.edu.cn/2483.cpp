#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int a[3],i;
		for (i=0;i<3;i++)
		scanf ("%d",&a[i]);
		int sum;
		sum=a[1]-a[2];
		if (sum<a[0])
		printf ("do not advertise\n");
		if (sum>a[0])
		printf ("advertise\n");
		if (sum==a[0])
		printf ("does not matter\n");
	}
	system("pause");
}
		
