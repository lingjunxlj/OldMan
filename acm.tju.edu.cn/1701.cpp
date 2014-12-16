#include <stdio.h>
#include <stdlib.h>
int c[1000000],d[1000000];
int main()
{	
	int x,y=0;
	scanf ("%d",&x);
	while (x--)
	{
		y++;		
		int a,b;
		scanf ("%d",&a);
		scanf ("%d",&b);		
		int t,i,j;
		for (i=0;i<b;i++)
		scanf ("%d",&c[i]);
		for (j=1;j<b;j++)
		for (i=0;i<b-j;i++)
		{
			if (c[i]>c[i+1])
			{
			t=c[i];
			c[i]=c[i+1];
			c[i+1]=t;
		    }
		}
		for (i=0;i<b;i++)
		d[b-i]=c[i];
		int sum=0,k=0;
		for (i=1;i<=b;i++)
		{
			
			
			sum+=d[i];
			k++;
		    if (sum>=a)
			break;
		    
		}
		if (sum<a)
		printf("Scenario #%d:\nimpossible\n\n",y);
		else
		printf("Scenario #%d:\n%d\n\n",y,k);
	}
	system("pause");
}
		
		
		
		
		
		
