#include<stdio.h>
int main()
{
	int a[1100]={0};
	int i,j,min;
	int M,N,temp,k;
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=M;i++)
	for(j=1;j<=M-i;j++)
	if(a[j]>a[j+1]) 
	{
		temp=a[j+1];a[j+1]=a[j];a[j]=temp;}
		j=2;
		k=a[M];
		for(i=M-1;i>=1;i--)
		{
			if(j>N) 
			{
				if(a[i]*N>k) 
				{
					k=a[i]*N;min=a[i];
				}
			}
		else if(a[i]*j>k) 
		{
			k=a[i]*j;min=a[i];
		}
		j++;}
		printf("%d %d\n",min,k);

}

