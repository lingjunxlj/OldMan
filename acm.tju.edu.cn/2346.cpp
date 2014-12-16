
#include<stdio.h>
#include<math.h>
long long x,y;
long long sum;
long long i,n;
int main()
{
	
	
	scanf ("%lld",&n);
	for(i=0;i<n;i++)
	{       
		
		

		scanf("%lld %lld",&x,&y);
		

		sum=(x+y)*(y-x+1)/2;
	
		printf("Scenario #%d:\n",i+1);

		printf("%lld\n",sum);

		printf("\n");
	}
	return 0;
}
