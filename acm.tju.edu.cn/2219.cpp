#include <iostream>
#include <cstdlib>
using namespace std;
int gcd(int a, int b) 
{
    if (a==0) 
	return b;
    return gcd(b%a,a);
}
int main()
{
	int x,y;
	while (cin>>x>>y&&x!=0&&y!=0)
	{
		int sum,i,a[101],g;
		sum=1;
		for (i=0;i<x;i++)
		{
			cin>>a[i];
			if (a[i]<y)
			sum=0;
		}
		if (sum==0)
		cout<<"NO"<<endl;
		else
		{
			g=a[0];
			for (i=0;i<x;i++)
			g=gcd(g,a[i]);
			if (y%g==0)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
	}
	system("pause");
}
