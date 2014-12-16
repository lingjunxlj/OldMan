#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char a[1000];
int main()
{
	
	while(1)
	{
		int i,b[200],sum=0;
		gets(a);
		if (a[0]=='0')
		break;
		for (i=0;i<strlen(a);i++)
		{
			b[i]=a[i]-48;
			sum+=b[i];
			if (sum>10)
			sum=sum-10+1;
		}
		cout<<sum<<endl;
	}
	system("pause");
}
	
