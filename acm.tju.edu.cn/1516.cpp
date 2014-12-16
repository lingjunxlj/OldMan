#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int a[3];
	int i;
	while(1)
	{
		
	   for (i=0;i<3;i++)
	   scanf ("%d",&a[i]);
	   if (a[0]==0)
	   break;
       int j=0,sum=0;
	   for (j=1;;j++)	
	   {
		   if (j%2==1)
		   sum+=a[1];
		   if (j%2==0)
		   sum-=a[2];
		   if (sum>=a[0])
		   break;
    	}
	printf ("%d\n",j);
     }
     system("pause");
}
