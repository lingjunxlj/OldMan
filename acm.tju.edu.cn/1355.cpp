#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int a[3001],b,d[3001];
int main()
{
	int x;
	while (scanf ("%d",&x)!=EOF)
	{
		int i,sum=0;
		for (i=0;i<3001;i++)
		d[i]=0;
		for (i=0;i<x;i++)
		cin>>a[i];
		for (i=0;i<x-1;i++)
		{
			b=(a[i]>a[i+1])?(a[i]-a[i+1]):(a[i+1]-a[i]);
			if(!d[b]&&b!=0&&b<=x-1)
			{
				sum++;
				d[b]=1;
			}
		}
		if(x==1&&a[0]==1)
			printf("Jolly\n");
		else if(x==1&&a[0]!=1)
			printf("Not jolly\n");
		else if(sum==x-1)
			printf("Jolly\n");
		else printf("Not jolly\n");

	}
}
		
		
		
		
