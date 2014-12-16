#include <stdio.h>
#include <stdlib.h>
int main ()
{
	 int x;
	 
	 while (1)
	 {
			scanf ("%d",&x);
			if (x==0) break;
			int i,a[x];
			for (i=0;i<x;i++)			
			scanf ("%d",&a[i]);
			int m=0,n=0;
			for (i=0;i<x;i++)
			{
				if (a[i]==0)
				m++;
				if (a[i]==1)
				n++;
			}
			printf ("Mary won %d times and John won %d times\n",m,n);
		}
		system("pause");
	}
			   
