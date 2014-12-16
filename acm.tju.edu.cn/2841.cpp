#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main ()
{
	while (1)
	{
		int x;
		scanf ("%d",&x);
		if (x==0)
		break;
        int a[200]={},i=0;
        int j,sum=0,s=1;
        while (x>0)
        {
			a[i]=x%2;
			x=x/2;
			i++;
		}	
		for (j=0;j<i;j++)
		{
		sum=sum+(s*a[i-j-1]);
		s=s*2;
	     }
		printf ("%d\n",sum);
	}
	system("pause");
}
			
        
         
         
         
         
         
         
         
