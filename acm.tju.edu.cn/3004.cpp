#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
int main()
{
	int x,q=0;
	
	cin>>x;
	while (x--)
	{
		q++;
		int y;
		cin>>y;
		char a[100];
		cin>>a;
		int i,len;
		len=strlen(a);
		for (i=(y-1);i<len;i++)
		a[i]=a[i+1];
		printf ("%d ",q);
		puts(a);
		
	}
	system("pause");
}
		
	
