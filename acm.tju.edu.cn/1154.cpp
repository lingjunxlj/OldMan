#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int a[2];
	int c=0;
	while (1)
	{
		int i,j;
		for (i=0;i<2;i++)
		scanf ("%d",&a[i]);
		if (a[0]==0)
		break;		
		c++;
		int b;
		int k=0;
		for (j=1;j<a[0];j++)
		for (i=1;i<j;i++)
		{	       		   
		   b=((float)(i*i+j*j+a[1])/(i*j)/1);	       
	       if (b==(float)(i*i+j*j+a[1])/(i*j))
	       k++;
		}
		printf ("Case %d: %d\n",c,k);
	}
	system ("pause");
}
	       
