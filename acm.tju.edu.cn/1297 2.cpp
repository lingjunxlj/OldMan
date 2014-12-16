#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1005];
int main()
{
	int t,n,i,max;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		max=0;
		for(i=0;i<n;i++)
		{
			if(max<a[i]*(n-i))
				max=a[i]*(n-i);
		}
		printf("%d\n",max);
	}
	return 0;
}

