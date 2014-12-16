#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
	int x,y=0;
	scanf ("%d",&x);
	getchar( );
	while (x--)
	{
		
		y++;
		
		char a[200]={},b[200]={};
		gets(a);		
		gets(b);
		printf ("%d ",y);		
		int len,i;
		len=strlen(a);
		for (i=0;i<len;i++)
		{
			if (a[i]!=' ')
			{
				
				printf ("%c",b[a[i]-'A']);
			}
			else 
		    printf (" ");
		}
		printf("\n");
	}
	system("pause");
}
