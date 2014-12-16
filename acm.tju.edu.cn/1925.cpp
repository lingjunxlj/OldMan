#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	
	while (1)
	{
		int x;
		scanf ("%d",&x);
		if(x==-1||x<2||x>9)
		break;
		int a[100],b[100],c[100];
		char d[50][50];
		int i;
		for (i=0;i<x;i++)
		{
			
			scanf ("%d",&a[i]);
			scanf ("%d",&b[i]);
			scanf ("%d",&c[i]);
			scanf ("%s",&d[i]);
		}
		int max=a[0]*b[0]*c[0],min=a[0]*b[0]*c[0],k,k1,s,s1;
		for (i=0;i<x;i++)
		{
			s=a[i]*b[i]*c[i];
		    if (min>=s)
		    {
				k=i;
		    	min=s;
			}
		}
		for (i=0;i<x;i++)
		{
			s1=a[i]*b[i]*c[i];
		    if (max<=s1)
		    {
		    	k1=i;
				max=s1;	    	
			}
		}
		printf("%s took clay from %s.\n",d[k1],d[k]);
	}
	system("pause");
}
		
		
		
		
