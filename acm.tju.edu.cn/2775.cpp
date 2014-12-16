#include <stdio.h>
int main()
{
	int i,T,n;
	int f[43];
	scanf("%d",&T);
	f[0]=1;
	f[1]=1;
	for(i=2;i<=42;i++)
	f[i]=f[i-2]+f[i-1];
	while(T--)
	{
		scanf("%d",&n);
		printf("%d %d\n",f[n],f[n+1]);
	}
	return 0;
}
