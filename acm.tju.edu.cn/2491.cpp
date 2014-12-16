#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
char str[1000]={},str1[2000]={};
int main()
{
	
	int len,len1;
	int a,i,j;
	char t;
	while(1)
	{
		cin>>str;
		if (str[0]=='.')
		break;
		cin>>a;
		if (a<=10){
		len=strlen(str);
		strcpy(str1,str);
		a=a-1;
		while (a--)
		{strcat(str1,str);}		
		len1=strlen(str1);
		puts(str1);
		for (j=1;j<len;j++)
		{			
			t=str1[0];
			for (i=0;i<len1-1;i++)
			{
				
				str1[i]=str1[i+1];
				
			}
			str1[len1-1]=t;
			puts(str1);
		
		}		
	}}
	system("pause");
}
