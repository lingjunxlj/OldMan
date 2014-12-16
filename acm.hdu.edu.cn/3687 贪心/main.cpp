#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int a[200][200];
int b[200];
int n,m,i,j,x,k,ans=0,p;

int main()
{
	while (scanf("%d %d", &n, &p), n)
	{
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		m = n * n;
		for (i = 0; i < m; i++)
		{
			scanf("%d", &x);
			x--;
			scanf("%d", &a[x][b[x]++]);
		}
		for (i = 0; i < n; i++)
			sort(a[i], a[i] + n);
		ans = 100000000;

		for (k = 1; k <= p - n + 1; k++)
		{
			x = 0;
			for (i = 0; i < n; i++)
				for ( j= 0; j < n; j++)
					x += abs(a[i][j] - k - j);
			if (ans > x)
				ans = x;
		}
		printf("%d\n",ans);
	}
	return 0;
}
