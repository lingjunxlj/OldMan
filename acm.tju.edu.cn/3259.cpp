#include <stdio.h>
#include <math.h>
int a [1000002] = {0};
int main ()
{
	int i, j;
	for (i=1;i<=1000000;i++) 
	{
		for (j=i;j<=1000002;j+=i)
		a[j]++;
	}
	for (i=1;i<=100;i++)
	printf ("%d  ",a[i]);
	int low,high;
	while ( scanf ("%d %d", &low, &high) != EOF ) 
	{
		int count=0;
		for (int i=low;i<=high;i++) 
		{
			if (i%a[i]==0)
			count++;
		}
		printf ("%d\n",count);
	}
	return 0;
}
