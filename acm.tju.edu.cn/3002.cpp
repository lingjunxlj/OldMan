#include <iostream>
#include <stdlib.h>
using namespace std;
int ban(int n)
{
	if (n%2==0)
	return n/2+1;
	else
	return (n+1)/2;
}
int main()
{
	int x;
	while (cin>>x&&x!=0)
	{
		int temp,a[150],i,j;
		for (i=0;i<x;i++)
		cin>>a[i];
		for (i=0;i<x;i++)
		for (j=0;j<x-i-1;j++)
		{
			if (a[j]>a[j+1])
			{
				temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
			}
		}
		int sum=0;
		for (i=0;i<ban(x);i++)
		sum+=ban(a[i]);
		cout<<sum<<endl;
	}
	system("pause");
}
			
			
