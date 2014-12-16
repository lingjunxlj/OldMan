#include <stdio.h>
#include <stdlib.h>
int main()
{
	int q=0;
	while (1)
	{
		q++;
		int x,y,z;
		scanf ("%d",&x);
		scanf ("%d",&y);
		scanf ("%d",&z);
		if (x==0&&y==0&&z==0)
		break;
		int a[100],b[100],i,j;
		for (i=0;i<x;i++)
		scanf ("%d",&a[i]);
		for (i=0;i<y;i++)
		scanf ("%d",&b[i]);
		int max=0,sum;
		int c[100];
		for(i=0;i<x;i++)
		c[i]=0;
		for (i=0;i<y;i++)
		{
			sum=0;
			if (c[b[i]-1]==0)
			{			
				c[b[i]-1]=1;
			}
			else 
			{								
				c[b[i]-1]=0;
			}
			for(j=0;j<y;j++)
			{
				if(c[j]==1)
		    	sum=sum+a[j];
			}	
				if (sum>max)
				max=sum;
			
			
		}
		printf("Sequence %d\n",q);
		if(max>z) printf("Fuse was blown.\n");
		else
		{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n",max);
		}
		printf("\n");
	}
	system("pause");
}	
		
		
		
