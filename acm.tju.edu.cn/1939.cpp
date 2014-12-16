#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[11][2];
	int i,j;
	int x;
	while (1)
	{
		scanf ("%d",&x);
		if (x==-1)
		break;
	for (i=0;i<x;i++)
	for (j=0;j<2;j++)
	scanf ("%d",&a[i][j]);
	int sum=a[0][0]*a[0][1];
	
	for (i=1;i<x;i++)
	{
		sum+=a[i][0]*(a[i][1]-a[i-1][1]);
	}
	printf ("%d miles\n",sum);
}
system("pause");
}
