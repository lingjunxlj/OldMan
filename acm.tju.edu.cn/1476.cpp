#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int n,i=1,j;
		scanf ("%d",&n);
		int s=1,k=0;
		while(n%2==0)
           {
               n=n/2;
               k++;
           }   		   		   		   
		printf ("%d %d\n",n,k);
	}
	system("pause");
}
		
