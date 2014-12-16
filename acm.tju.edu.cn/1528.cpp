#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	while (x--)
	{
		int i,j,a,max=0;
		cin>>a;
		long long b[200];
		for (i=0;i<a;i++)
		{
			cin>>b[i];
			if (b[i]>max)
			max=b[i];
		}
		for (i=1;;i++)
		{	
			int s=0;
			for (j=0;j<a;j++)
			if (max*i%b[j]==0&&max!=b[j])
			s++;
			if (s==(a-1))
			{
				cout<<max*i<<endl;
				break;
			}
		}
	}
		system("pause");
}
