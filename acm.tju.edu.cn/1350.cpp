#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	
	while (1)
	{
		
		char a[100]={0},b[100]={0},c[100]={0},d[100]={0};
		int len1,len2,j;
		cin>>a;
		cin>>b;
		if (a[0]=='0'&&b[0]=='0')
		break;
		len1=strlen(a);
		len2=strlen(b);
		int sum,s=0,k=0,i;
		for (i=0;i<100;i++)
		{
			c[i]='0';
			d[i]='0';
		}	
		for (i=0;i<len1;i++)
		c[i]=a[len1-i-1];
		for (i=0;i<len2;i++)
		d[i]=b[len2-1-i];
		i=0;
		while (i<100)
		{		
			sum=c[i]-'0'+d[i]-'0'+s;			
			if (sum>9)
			{
				s=1;
				k++;
			}
			else
			s=0;
			i++;
		}
		if (k==0)
		printf ("No carry operation.\n");
		else if (k==1)
		printf ("%d carry operation.\n",k);
		else
		printf ("%d carry operations.\n",k);
	}
	system("pause");
}
	
	
	
	
