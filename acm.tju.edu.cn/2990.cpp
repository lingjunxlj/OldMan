#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		int a,a1[200],b,b1[200],i,j;
		cin>>a;
		for (i=0;i<a;i++)
		cin>>a1[i];
		cin>>b;
		for (i=0;i<b;i++)
		cin>>b1[i];
		int s=0;
		for (i=0;i<a;i++)
		for (j=0;j<b;j++)
		{
			if (a1[i]+b1[j]==0)
			s++;
		}
		cout<<s<<endl;
	}
	system("pause");
	return 0;
} 
		
		
