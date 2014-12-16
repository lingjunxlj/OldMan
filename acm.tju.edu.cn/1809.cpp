#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int x;
	while (cin>>x&&x!=0)
	{
		double temp,sum=0,a[x];
		int i,j,flag=0;
		for (i=0;i<x;i++)
		cin>>a[i];
		
		{
			for (i=0;i<x;i++)
			for (j=0;j<x-i-1;j++)
			{
				if (a[j]>a[j+1])
				{
					temp=a[j+1];
					a[j+1]=a[j];
					a[j]=temp;
				}
			}
			
			for (i=0;i<x-1;i++)
			{
				sum+=a[i];
				for(j=i+1;j<x;j++)			
				if (sum>=a[j])	
				{
					flag=1;
					goto out;
				}				
			}
			out:
			if (flag)
			cout<<"YES"<<endl;
			else
			cout<<"NO"<<endl;
		}
	}
	system("pause");
}
				
				
				
				
				
