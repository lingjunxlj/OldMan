#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		char str[101]={};
		scanf ("%s",str);
		int len,i;
		len=strlen(str);
		if (str[0]=='a'||str[0]=='e'||str[0]=='i'||str[0]=='o'||str[0]=='u')
		{
		str[len]='c';
		str[len+1]='o';
		str[len+2]='w';
		printf ("%s\n",str);
	}
		else
		{
			char b;
			b=str[0];
			for (i=0;i<len;i++)
			str[i]=str[i+1];			
			str[len-1]=b;
			str[len]='o';
			str[len+1]='w';
			printf ("%s\n",str);
		}
	}
	system("pause");
}
