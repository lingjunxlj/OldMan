#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
int p(int x)
{
	int i;
	if (x==1)
	cout<<"- -";
	else
	{
		p(x-1);
		for(i=0;i<(int)pow(3,x-1);i++)
		cout<<" ";
		p(x-1);
	}
}
int main()
{
	int x;
	while (cin>>x)
	{
		if (x==0)
		cout<<"-";
		else
		p(x);
		cout<<endl;
	}
	system("pause");
}
