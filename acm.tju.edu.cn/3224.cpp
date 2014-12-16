#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		long long m,n;
		cin>>n>>m;
		if (n==1&&m==1)
		cout<<"0"<<endl;
		else
		cout<<n*m-1<<endl;
	}
	system("pause");
}
		
