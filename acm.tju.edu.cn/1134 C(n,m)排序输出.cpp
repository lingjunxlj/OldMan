#include <iostream>
using namespace std;
int num[15],c[15],x;
int D(int n,int m)
{
	int i,k,j;
	if (m==6)
	{
		for (i=0;i<5;i++)
		cout<<c[i]<<" ";
		cout<<c[5]<<endl;
		return 0;
	}
	for (i=n;i<x;i++)
	{
		c[m]=num[i];
		D(i+1,m+1);

	}
	return 0;
}
int main()
{
	int i,j=0;
	while (cin>>x,x)
	{
		if (j!=0)
		cout<<endl;
		j++;
		for (i=0;i<x;i++)
		cin>>num[i];
		sort(num,num+x);
		D(0,0);


	}
}
