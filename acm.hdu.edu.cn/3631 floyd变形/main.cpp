#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int map[400][400];
bool flag[400];
int n,m,q;
int main()
{
	int tt = 0;
	while (scanf("%d%d%d", &n,&m,&q))
	{
		tt++;

		if (n == 0 && m == 0 && q == 0)
		break;
		if (tt != 1)
		printf("\n");
		int x , y, z;
		for (int i = 0 ; i <= n ; i++)
			for (int j = 0 ; j <= n ; j++)
				{
					map[i][j] = 0x7fff;
					if ( i == j)
					map[i][j] = 0;
				}
		for (int i = 0 ; i < m ; i++)
		{
			scanf("%d %d %d", &x, &y, &z);
			if (z < map[x][y])
			map[x][y] = z;
		}
		memset(flag, 0, sizeof(flag));
        printf("Case %d:\n", tt);
		while (q--)
		{
			int a, b, c, d;
			scanf("%d", &a);
			if (a == 0)
			{
				scanf("%d", &b);
				if (flag[b] == 0)
				{
					flag[b] = 1;
					for (int i = 0 ; i < n ; i++)
						for (int j = 0 ; j < n ; j++)
							map[i][j] =min(map[i][j], map[i][b] + map[b][j]);
				}
				else
				printf("ERROR! At point %d\n", b);
			}
			if (a == 1)
			{
				scanf("%d %d", &c, &d);
				if (flag[c] == 0 || flag[d] == 0)
					printf("ERROR! At path %d to %d\n", c, d);
				else if (map[c][d] == 0x7fff)
					printf("No such path\n");
				else
					printf("%d\n",map[c][d]);
			}
		}

	}
}
