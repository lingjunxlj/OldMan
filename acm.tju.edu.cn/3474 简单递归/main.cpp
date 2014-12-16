#include <iostream>
using namespace std;

int num[2205];

int Sum(int s,int e)
{
	if(e-s+1==2)
	{
		return num[s]*num[e];
	}
	if(e-s+1==3)
	{
		return num[s]*num[s+1];
	}
	int mid=(s+e)/2;
	return Sum(s,mid)+Sum(mid+1,e);
}

int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		num[i]=i;
	}
	int sum;
	sum=Sum(1,n);
	cout<<sum<<endl;
}
