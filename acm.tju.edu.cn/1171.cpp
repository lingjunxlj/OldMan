#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;
int f[1000001]={0};
int a[1000001]={0};
int c[1000001]={0};
int main()
{
	 long i,j;
	 c[1]=1;
	 for (i=2;i*i<=1000000;i++)
 	 for (j=2;j*i<=1000000;j++)
 	 c[i*j]=1;
 	 long ji;
     ji=0;
 	 for (long i=2;i<=1000000;i++)
  	 if (c[i]==0)
  	 { 		 
  		 a[ji]=i;
		 ji+=1;
     }
    while (1)
    {
		long x,n,m,k=0,q,p;
		cin>>x;
		if (x==0)
		break;
		for (n=0;x>a[i];n++)
		{
			if (k>0)
			break;
			for (m=1;m<(int)sqrt(n)+1;m++)
			{
				if (x==(a[m]+a[n]))
				{
					p=a[m];
					q=a[n];
					k++;	
					break;
				}
			}
		}
		printf ("%ld = %ld + %ld\n",x,p,q);
	}
	system("pause");
}
		
		
		
		
		
		
		
    
    
    
