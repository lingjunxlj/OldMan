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
		int m=0,n=0;
		for (i=0;i<strlen(a);i++)
		m=m+a[i];
		for (i=0;i<strlen(b);i++)
		n=n+b[i];
		if (m==n)
			cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
		
		
	}system("pause");
}
