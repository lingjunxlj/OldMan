#include <cstdio>
#include <cstdlib>
int main()
{
	int n;
	scanf("%d",&n);
	while(1)
	{
		if(n==0) break;
		int a[n],b[n];
		int i,sum1=0,sum2=0;
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		for(i=0;i<n;i++)
		{
			if(a[i]-b[i]>1)
			sum1=sum1+a[i];
			else if(a[i]-b[i]==1)
			{
				if(a[i]==2&&b[i]==1)
				sum2=sum2+6;
				else
				sum2=sum2+(a[i]+b[i]);
			}
			else if(a[i]-b[i]==-1)
			{
				if(a[i]==1&&b[i]==2)
				sum1=sum1+6;
				else
				sum1=sum1+(a[i]+b[i]);
			}
			else if(a[i]-b[i]<-1)
			sum2=sum2+b[i];
			else ;
		}
		printf("A has %d points. B has %d points.\n",sum1,sum2);
		scanf("%d",&n);
		if(n) printf("\n");
	}
	/*system("pause");*/
}
