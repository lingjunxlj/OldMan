#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int a;
	while (1)
	{		
		cin>>a;
		if (a==0||a>20)
		break;
		char str[100];
		int len,i,j,s,max;
		cin>>str;
		
		len=strlen(str);
	
		int str1[100];
		for (i=0;i<100;i++)
		str1[i]=0;
	    s=0;max=0;

		for (i=0;i<len;i++)
		{
			if (str1[int(str[i]-'A')]==0)
			{
				
				s++;
				str1[int(str[i]-'A')]=1;
			}
			else if (str1[int(str[i]-'A')]==1)
			{
				
				s--;
				str1[int(str[i]-'A')]=0;
				
				
			}
					
			if (s>max)
			max=s;
		}
		
		if (max<=a)
		printf ("All customers tanned successfully.\n");
		else
		printf ("%d customer(s) walked away.\n",max-a);
	}
	system ("pause");
	return 0;
}	
			
			
			
			
	
