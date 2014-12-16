#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int main ()
{
	int y=0;
	while (1)
	{
		y++;
		int x,i,a[100],sum=0,arr,s=0;
		cin>>x;
		if (x==0)
		break;
		for (i=0;i<x;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		arr=sum/x;
		for (i=0;i<x;i++)
		{
			if (a[i]>arr)
			{
				s+=(a[i]-arr);
			}
		}
		printf ("Set #%d\nThe minimum number of moves is %d.\n\n",y,s);
	}
	system("pause");
}
