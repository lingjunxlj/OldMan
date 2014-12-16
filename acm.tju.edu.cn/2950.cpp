#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main()
{
	int a[50],i,j,sum=0,k=0,m,n;
	for (i=0;i<9;i++)
	cin>>a[i];
	for (i=0;i<9;i++)
	sum+=a[i];
	
	for (i=0;i<9;i++)
	for (j=0;j<9;j++)
	{
					
			if ((sum-a[i]-a[j])==100)
			{
				m=i;
				n=j;
				k++;
				for (i=0;i<9;i++)
				{					
					if (i!=m&&i!=n)
					cout<<a[i]<<endl;
				}
			
			}
		
	}
	if (k==0)
	printf ("Wrong Answer\n");
	system("pause");
}

	
			
	
