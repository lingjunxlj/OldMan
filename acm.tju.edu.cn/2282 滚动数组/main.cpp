#include <cstdio>
#include <string>
int n, k;
int main()
{
	bool a[205], b[205];
	int t;
	scanf("%d %d",&n,&k);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	scanf("%d",&t);
	a[t%k+101]=1;
	while(--n)
	{
		scanf("%d",&t);
		for(int i=0; i<k+101; i++)
		{
			if(a[i])
			{
				b[(i-101+t)%k+101]=1;
				b[(i-101-t)%k+101]=1;
			}
		}
		for(int i=0; i<k+101; i++)
		{
			a[i]=b[i];
			b[i]=0;
		}
	}
	if(a[101])
    printf("Divisible\n");
	else
	printf("Not divisible\n");
}
