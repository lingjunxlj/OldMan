#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int c(int a, int b)   
{
	int n;
	while(a!=0)
	{
       n=b%a; b=a; a=n;
	}
	if(b==1) return 1;
	else     return 0;
} 
int main()
{
	int x;
	while (scanf ("%d",&x),x>0)
	{
		int n[50],i,j,s;
		double y;
		for (i=0;i<x;i++)
		scanf ("%d",&n[i]);
		s=0;
		int m;
		for (i=0;i<x-1;i++)
		for (j=i+1;j<x;j++)
		{		    
	         if (c(n[j],n[i]))
	         s++;
		}
		
		if(s>0)
		{
			y = pow(3.0*x*(x-1)/s, 0.5);
		    printf("%.6lf\n", y);
		}
		else   printf("No estimate for this data set.\n");
	}
	system("pause");	
}
