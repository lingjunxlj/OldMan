#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		char a[100],b[100];
		int c[100],d[100],i;
		cin>>a;
		cin>>b;
		memset(c,0,sizeof(c));
		memset(d,0,sizeof(d));
		for (i=0;i<strlen(a);i++)
		if (a[i]>='A'&&a[i]<='Z')
		a[i]+=32;
		for (i=0;i<strlen(b);i++)
		if (b[i]>='A'&&b[i]<='Z')
		b[i]+=32;
		for (i=0;i<strlen(a);i++)
		c[a[i]-97]++;
		for (i=0;i<strlen(b);i++)
		d[b[i]-97]++;
		if (strlen(a)!=strlen(b)||strcmp(a,b)==0)
		cout<<"No"<<endl;
		else
		{
			int k=0;
			for (i=0;i<strlen(a);i++)
			if (c[i]==d[i])
			k++;
			if (k==strlen(a))
			cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
		}
		
	}system("pause");
}
			
			
			
			
			
			
			
