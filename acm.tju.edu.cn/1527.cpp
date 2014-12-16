#include <stdio.h>
#include <stdlib.h>
int main ()
{
	while (1)
	{
		
	   int a[6];
	   int i;
	   for (i=0;i<6;i++)	   
	   scanf ("%d",&a[i]);	
 	   if (a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0)
 	   break;
	   int s,su,sum;
	   s=a[0]+a[1];
	   su=a[2]+a[4];
	   sum=a[3]+a[5];
	   int x=0,y=0;
	   x=sum-a[0];
	   y=su-a[1];
       
		printf ("Anna's won-loss record is %d-%d.\n",x,y);
	}
	system("pause");
}
