#include <iostream>
#include <stdlib.h>
#include<math.h>
using namespace std;
int a[10000050],b[10000005];
void sushu()
{
	long long i,j;
	for(i=2;i<1001000;i++)
	{
		if(a[i]==1)
			continue;
		for(j=2;i*j<1001000;j++)
			a[i*j]=1;
	}
	j=0;
	for(i=2;i<1001000;i++)
		if(a[i]==0){
			b[j]=i;
			j++;
		}
}

int main()
{
	sushu();
	
	long x,i;
	while(cin>>x&&x!=0)
	{
		long sum=0;
		for(i=0;i<x/2;i++)
		if (x%b[i]==0)
		sum++;
		cout<<x<<" : "<<sum<<endl;
	}
	system("pause");
}
