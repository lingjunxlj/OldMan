#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	char a[200];
	int b[200];
	while (1)
	{
		int i,len;
		gets(a);
		if (a[0]=='0')
		break;
		len=strlen(a);
		for (i=0;i<len;i++)
		b[i]=a[i]-48;
		long int sum=0,n=1;
		for (i=0;i<len;i++)
		{
			n=n*2;
			sum=sum+b[len-i-1]*(n-1);
		}
		
		printf ("%ld",sum);
		printf ("\n");
	}
	system("pause");
}
