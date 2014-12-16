#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a;
	int i;
	
	while (scanf("%d",&a)!=EOF) { 
		if (!a) break;  

    	for(i=1;a!=1;i++)
	   {   
		if (a%2==0) a=a/2;
	    else a=3*a+1;
	   }
     printf ("%d\n",i);}	 		
	/* system("pause");*/
}
     
