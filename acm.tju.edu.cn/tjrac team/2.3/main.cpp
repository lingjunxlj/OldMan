#include <iostream>
#include <cstring>
using namespace std;

int fa[100010];

void init(int n)
{
	for(int i = 0; i <= n; i++)
		fa[i] = i;
}

int find(int x)
{
	if(fa[x] != x) fa[x] = find(fa[x]);
	return fa[x];
}

void Union(int a, int b)
{
	int x = find(a), y = find(b);
	fa[y] = x;
}

bool judge(int a, int b)
{
	int x = find(a), y = find(b);
	if(x == y)
		return 1;
	else
		return 0;
}

int main()
{
	int n, m, k;
	while(scanf("%d %d %d", &n, &m, &k) != EOF)
	{
		int i;
		init(n);
		int x, y;
		for(i = 0; i < m; i++)
		{
			scanf("%d %d", &x, &y);
			if(x <= y)
				Union(x, y);
			else
				Union(y, x);
		}
		for(i = 0; i < k; i++)
		{
			scanf("%d %d", &x, &y);
			if(judge(x, y))
				printf("YES\n");
			else if(!judge(x, y))
				printf("NO\n");
		}
	}
	return 0;
}

