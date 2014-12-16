#include <iostream>
using namespace std;
int minm[1001];
int main()
{
	int c,n,value[101];
	cin>>c>>n;
	int i,j;
	for (i=0;i<n;i++)
	cin>>value[i];
	for (i=0;i<1001;i++)
	minm[i]=1500;
	minm[0]=0;
	for (i=1;i<=c;i++)
	for (j=0;j<n;j++)
	{
		if (value[j]<=i&&minm[i-value[j]]+1<minm[i])
		minm[i]=minm[i-value[j]]+1;
	}
	cout<<minm[c]<<endl;
	
}
	
	
	
