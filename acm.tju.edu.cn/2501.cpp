#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char a[80];	
	int x;
	scanf("%d",&x);
	while (x--)
	{
		int i,j=1,sum=0,len;
		scanf("%s",a);
		len=strlen(a);
		for (i=0;i<len;i++)
		{
			if (a[i]=='O')
			{
			sum+=j;
			j++;
			}
			if(a[i]=='X') 
			j=1;	
		}
		printf ("%d\n",sum);		    
}
	/*system("pause");*/
	}
	
