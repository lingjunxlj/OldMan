#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n1, n2;
bool map[10000];
int value[10000];
int q[11000];
int c[4]= {1, 10, 100, 1000};
bool bfs()
{
	int front = 0, rear = 0;
	q[rear++] = n1;
	value[n1] = 0;
	while(front < rear)
	{
		int temp = q[front++];
		if(temp == n2)
			return true;

		for(int i = 0; i < 4; ++i)
		{
			int digit = (temp/c[i]) % 10;
			for(int j = 0; j < 10; ++j)
			{
				int changed = temp - digit*c[i] + j*c[i];
				if(changed >= 1000 && j != digit && map[changed] && value[changed] == -1)
				{
					q[rear++] = changed;
					value[changed] = value[temp]+1;
				}
			}
		}
	}
	return false;
}
int main()
{
	int n;
	for(int i = 1; i <= 9999; ++i)
		map[i] = true;
	for(int i = 2; i < 5000; ++i)
		if(map[i])
		{
			for(int j = 2*i; j <= 9999; j += i)
				map[j] = false;
		}
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d%d", &n1, &n2);
		memset(value, -1, sizeof(value));
		if(map[n1] && map[n2])
		{
			if(bfs())
				printf("%d\n", value[n2]);
			else
				printf("Impossible\n");
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
