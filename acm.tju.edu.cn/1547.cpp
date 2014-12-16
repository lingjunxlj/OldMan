#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char a[201];
int main()
{
	int row,x,len,i,j,k;
	while(scanf("%d",&x)==1 && x!=0)
	{
		scanf("%s",&a);
		len=strlen(a);
		row=len/x;
		for(i=0;i<x;i++)
			for(j=0,k=-i-1;j<row;j++)
			{
				if(j%2==0) k+=2*i+1; 
				else k+=2*(x-i)-1;
				printf("%c",a[k]);
			}
		printf("\n");
	}
	system("pause");
	return 0;
}
