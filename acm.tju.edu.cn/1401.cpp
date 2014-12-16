#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char a[1000000],b[1000000];
int main()
{
	 while (cin>>a>>b)
	 {
		
			
			int len1,len2,i=0,j=0;
			len1=strlen(a);
			len2=strlen(b);
			while(i<len1&&j<len2)
			{
				if(a[i]==b[j])
    			{
					i++;
					j++;
				}
    			else
				 j++;
			}

			if (i==len1)
			printf ("Yes\n");
			else 
			printf ("No\n");
	}
	system("pause");
}
