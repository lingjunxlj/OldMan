#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int a[10001] = {0};
	int num = 0;
	int n , m;
		int i , j = 0;
		for(i = 1 ; i < 10001; i++)
		{
			num = i;
			if(a[i]==0)
				cout<<i<<endl;
			
			n = i;	
			while( n )
			{
				m = n % 10;
				num += m;
				n /= 10;
			}
			if(num < 10001)
				a[num] = 1;
		}
		system("pause");	
	return 0;
}

