#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
	
	while (1)
	{
		char q,a[100]={},b[100]={},c[100]={};
		int i=0,j=0,len1,len2;
		while (1)
		{
			q=getchar();
			if (q=='\n')
			break;
			a[i]=q;
			i++;
			
		}
		if (strcmp(a,"THE END.")==0)
		break;
		len1=strlen(a);
		for (i=0;i<len1;i++)
		{
			if(a[i]>='a' && a[i]<='z') 							
			b[j++]=a[i];				 
   			else if(a[i]>='A' && a[i]<='Z') 
			b[j++]=char(a[i]-'A'+(int)'a');

		}
		
		len2=strlen(b);
		for (i=0;i<len2;i++)
		c[len2-i-1]=b[i];
		if (strcmp(b,c)==0)
		printf ("Yes\n");
		else
		printf ("No\n");
		
	}
	system("pause");
}
