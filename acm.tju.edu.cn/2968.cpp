#include <iostream>
using namespace std;
int main()
{
	int n,m;
	while (cin>>n>>m)
	{
		int s,k;
		s=n*n;
		k=n+1;
		while (m%n!=1&&m>n)
			m=m-k;
		cout<<m;
		while (m+k<=s&&m%n!=0)
		{
			m+=k;
			cout<<" "<<m;
		}
		cout<<endl;
	}
}
