#include <stdio.h>
#include <stdlib.h>
struct car
	{
		long long xl;
		long long speed;
		long long wd;
	};
	struct car car[1000];
	struct car t;
int main()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		long long a,b,i,j;
		scanf ("%lld %lld",&a,&b);
		if (a<2||a>1000)
		break;
		if (b<1||b>a)
		break;
		for (i=0;i<a;i++)
		scanf ("%lld %lld %lld",&car[i].xl,&car[i].speed,&car[i].wd);
		for (i=0;i<a;i++)
		for (j=0;j<a-j;j++)
		{
			if (car[j].speed<car[j+1].speed)
			{
				t=car[j];
				car[j]=car[j+1];
				car[j+1]=t;
			}
		}
	
		for (i=0;i<a-1;i++)
		if (car[i].wd==car[i+1].wd)
		{			
			if (car[i].wd<car[i+1].wd)
			{
				t=car[j];
				car[j]=car[j+1];
				car[j+1]=t;
			}
		}
		printf("%lld\n",car[b-1].xl);
	}
	system("pause");
}
		
			
			
			
			
			
			
			
			
			
			
			
			
			
			
