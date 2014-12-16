#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int n,p,q;
	while (cin>>n>>p>>q)
	{

			n%=(q+p);
			if(n > p || !n)
			cout<<"WIN"<<endl;
			else
			cout<<"LOST"<<endl;
		
	}
	system("pause");
}
