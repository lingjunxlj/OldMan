#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int a1,b1,a2,b2,a3,b3;
	cin>>a1>>b1>>a2>>b2>>a3>>b3;
	if (a1==a2)
	cout<<a3<<" ";
	if (a1==a3)
	cout<<a2<<" ";
	if (a3==a2)
	cout<<a1<<" ";
	if (b1==b2)
	cout<<b3<<endl;
	if (b1==b3)
	cout<<b2<<endl;
	if (b3==b2)
	cout<<b1<<endl;
	system("pause");
}
	
