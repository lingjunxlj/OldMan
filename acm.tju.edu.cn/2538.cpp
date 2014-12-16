#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int x;
	int k=0;
	scanf ("%d",&x);
	while (x--)
	{
		k++;
		int a;
		scanf ("%d",&a);
		int i,j,s=0,sum=0;
		for (i=1;i<=a;i++)
		{				
		s=0;
		for (j=1;j<=(i+1);j++)
		{
			s=s+j;			
		}
		sum=sum+i*s;
				
	    }		    
		printf ("%d %d %d\n",k,a,sum);
	}
	system("pause");
}
		
		
		
		
		
