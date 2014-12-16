#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int b[100],i,j,m,s,k;
char a[100];
int main()
{
	while (1)
	{
		
		gets(a);
		if(strcmp(a,"end")==0)
		break;		
		memset (b,0,sizeof(b));
		m=0;
		for (i=0;i<strlen(a);i++)
		{
			if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
			{
				m++;
				break;
			}
		}
		if(m==0)
        printf("<%s> is not acceptable.\n",a);
		for (i=0;i<strlen(a);i++)
		{
			if (a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
			{
				b[i]=1;
			}
		}
		k=0;
        if(strlen(a)!=1)
		{
        	for(i=1;i<strlen(a)-1;i++)
        	if(b[i]==b[i-1]&& b[i+1]==b[i])
         	k++;
		}
        if(k!=0) 
		printf("<%s> is not acceptable.\n",a);
		s=0;
        for(i=0;i<strlen(a);i++)
            if(a[i]==a[i+1]&& a[i]!='e'&& a[i]!='o')
                s++;
        if(s!=0)
         printf("<%s> is not acceptable.\n",a);
        if(m!=0&& s==0&& k==0)
         printf("<%s> is acceptable.\n",a);
     
    }
  system("pause");      
}
