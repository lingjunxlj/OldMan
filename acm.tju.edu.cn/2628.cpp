#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	char str1[100],str2[100];
	int len1,len2,i,j;
	while(m--)
	{
		cin>>str1>>str2;
		j=0;
		len1 = strlen(str1);
		len2 = strlen(str2);
		for(i = 0 ; i < len1 ; i ++)
		{
			if( str1[i] == str2[j])
			{
				j++;
			}
			
		}
	    char b[100];
		if(j == len2)
		cout<<"YES\n";
		
		else
		{
			j=0;
			for (i=0;i<len1;i++)
			b[i]=str1[len1-1-i];
		
			for(i = 0;i <len1;i ++)
			{
				if( b[i] == str2[j])
				{
					j++;
				}
			
			}
			
			if(j == len2)
				cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		
	}
	system ("pause");
}
