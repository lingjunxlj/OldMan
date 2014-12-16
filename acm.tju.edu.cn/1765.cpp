#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int a[1100],b[1100];
int main()
{
	int i,x,j,s;
	cin>>x;
	for (i=0;i<x;i++)
	cin>>a[i];
	int max,l=1;
	for (i=1;i<x;i++)
	{
		max=1;
		b[0]=1;
		for (j=0;j<i;j++)
		{
			if (a[j]>a[i])
			{
				if (b[j]+1>max)
				max=b[j]+1;
			}
		}
		b[i]=max;
		if(max>l)
		l=max;
	}
	cout<<l+1<<endl;
	system("pause");
}
		
		
	
