#include <iostream>
#include <stdlib.h>
using namespace std;
int a[10005];
int main()
{
	int x;
	cin>>x;
	int i,j,temp=1,b;
	for (i=0;i<x;i++)
	cin>>a[i];
	b=a[0];
	for (i=1;i<x;i++)
	{
		if (b<a[i])
		temp++;
	}
	cout<<temp<<endl;
	system("pause");
}
