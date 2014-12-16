#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int x;
	int y=0;
	scanf("%d",&x);
	while (x--)
	{
		int i,n;
		scanf("%d",&n);
		char a[100];
		int k=0;
		y++;
		for (i=0;i<n;i++)
		 {				
		      scanf ("%s",a);
		      if (strcmp(a,"sheep")==0)
		      k++;
		  }
		  printf ("Case %d: This list contains %d sheep.\n",y,k);
		  if (x!=0) printf ("\n");
	 }
		system("pause");
}
