#include <iostream>
#include <stdlib.h>
using namespace std;
int a[10000];
int main()
{
	int x;
	while (cin>>x&&x!=0)
	{
		int max,sum=0,i;
		for (i=0;i<x;i++)
		cin>>a[i];
		max=0;
		for (i=0;i<x;i++)
		{
			
			sum+=a[i];
			if (sum<0)
			sum=0;
			if (sum>=max)
			max=sum;
		}
		if (max>0)
		cout<<"The maximum winning streak is "<<max<<"."<<endl;
		else
		cout<<"Losing streak."<<endl;
	}
	system("pause");
}
			
