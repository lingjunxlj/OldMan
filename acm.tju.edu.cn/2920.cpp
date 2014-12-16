#include <iostream>
using namespace std;
int main()
{
	long long n;
	while (cin>>n)
	{
		long long sum;
		sum=n*(n+1)/2*(n+2)/3;
		cout<<sum<<endl;
	}
}
