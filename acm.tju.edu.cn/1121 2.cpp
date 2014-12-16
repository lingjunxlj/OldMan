#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[100],b[100],c[100];
int i,j,k;
int main()
{
	
	gets(a);
	gets(b);
	puts(b);
	puts(a);
	
	while (gets(c)!=NULL)
	{
		for (i=0;i<strlen(c);++i)
		{
			k=0;
			for (j=0;j<strlen(a);++j)
			{
				if (a[j]==c[i])
				{
					printf("%c",b[i]);
					k=1;
				}
			} 
			if(k!=1)
			printf("%c",c[i]);
		}
		printf("\n");		
	}
}
