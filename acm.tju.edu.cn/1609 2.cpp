#include <cstdio>
#include <cstdlib>
int main()
{
	int n,m,c,l=0;
	while(scanf("%d %d %d",&n,&m,&c)!=EOF)
	{
		l++;
		if(n==0&&m==0&&c==0) break;
		int a[n],b[m],h[n];
		int i,sum=0,max=0,j;
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<m;i++)
		scanf("%d",&b[i]);
		for(i=0;i<n;i++)
		h[i]=0;
		int k;
		for(i=0;i<m;i++)
		{
			sum=0;
			k=b[i];
			if(h[k-1]==1)
			h[k-1]=0;
			else
			h[k-1]=1;
			for(j=0;j<n;j++)
			{
				if(h[j]==1)
		    	sum=sum+a[j];
			}
			if(max<sum) max=sum;
		}
		printf("Sequence %d\n",l);
		if(max>c) printf("Fuse was blown.\n");
		else
		{
			printf("Fuse was not blown.\n");
			printf("Maximal power consumption was %d amperes.\n",max);
		}
		printf("\n");
	}
	system("pause");
}
			
