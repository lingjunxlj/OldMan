#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while(x--)
	{
		int i,a[4],b[3];
		for (i=0;i<4;i++)
		cin>>a[i];
		for (i=0;i<3;i++)
		cin>>b[i];
		if (abs(a[0]-b[0])>=b[2]&&abs(a[2]-b[0])>=b[2]&&abs(a[1]-b[1])>=b[2]&&abs(a[3]-b[1])>=b[2])
		cout<<"Just do it"<<endl;
		else
		cout<<"Don't get close to it"<<endl;
	}
	system("pause");
}
		
		
		
		
		
