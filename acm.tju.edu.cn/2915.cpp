#include <cstdio>

const int MAX=120000;
int sweet[MAX],mark[MAX],n,c;
int main()
{
	int i,j,a,b,sum;
	while (scanf("%d%d",&c,&n),c)
	{
		for (i=0;i<n;i++)
		{
			mark[i]=0;
			scanf("%d",&sweet[i]);
		}
		sum=0;
		for (i=0;i<n;i++)
		{
			sum=(sum+sweet[i])%c;
			if (sum==0)
			{
				a=1;
				b=i+2;
				break;
			}
			if (mark[sum])
			{
				a=mark[sum]+1;
				b=i+2;
				break;
			}
			mark[sum]=i+1;
		}
		for (i=a;i<b-1;i++)
		printf("%d ",i);
		printf("%d\n",i);
	}
}
