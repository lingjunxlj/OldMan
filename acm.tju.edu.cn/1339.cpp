#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;
	scanf ("%d",&x);
	while(x--)
	{
		int a,b;
		scanf("%d",&a);
		scanf ("%d",&b);
		int sum=0,m=0,n=0;
		int i;
		if ((b-a)%2==0)
		{
			for (i=0;i<(b-a)/2;i++)
			{
				m++;
				sum+=m;
			}
			sum=sum-m;
		}
		if ((b-a)%2==1)
		{
			
