#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	int x,y=0;
	cin>>x;
	getchar();
	while (x--)
	{
		y++;
		int len,i;
		char str[100];
		gets(str);
		len=strlen(str);
		for (i=0;i<len;i++)
		str[i]=(str[i]+1-65)%26+65;
		printf ("String #%d\n",y);
		puts(str);
		printf ("\n");
	}
	system("pause");
}
