#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{
	int x;
	scanf ("%d",&x);
	char ch;
	ch = getchar();
	while (x--)
	{
		char a[80]={},b[80]={};
		
		gets(a);
		int i,len;
		len=strlen(a);
		for (i=0;i<len;i++)
		b[i]=a[len-1-i];
		puts(b);
	
	}
	system("pause");
}
