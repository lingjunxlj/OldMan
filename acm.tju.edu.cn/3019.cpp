#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
long long a[100];
long long sum;
int main()
{
	int x;
	while(1)
	{
		cin>>x;
		if (x==0)
		break;
		sum=0;
		int i;
		for (i=1;i<=x;i++)
		scanf ("%lld",&a[i]);
		
		while (x>0)
		{
			for(i = 1; i <x;i++)
                a[i] = a[i] + a[x];
            sum = sum + a[x];
            x--;
		}
		printf("%lld\n",sum);
	}
	system("pause");
}
		
