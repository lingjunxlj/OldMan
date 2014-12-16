#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int x,y=0;
	cin>>x;
	while (x--)
	{
		y++;
		int n,i,a[100];
		cin>>n;
		a[1]=2;
		a[2]=3;
		if (n>2)
		a[n]=a[n-1]+a[n-2];
		cout<<"Scenario #"<<y<<":"<<endl<<a[n]<<endl<<endl;
	 }
  	 system("pause");
}	
