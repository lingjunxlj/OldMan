
#include <stdio.h>
#include <memory.h>
bool odd[1000001];
int main()
{
	int i, j;
	int x;
	memset(odd, true, sizeof(odd));
	for(i = 2; i <= 500000; i++)
	{
		if(odd[i])
		{
			for(j = 2; j < 1000000/i; j++)
			{
				odd[i + j * i] = false;
			}
		}
	}
	scanf("%d", &x);
	while(x > 0)
	{
		for(i = 3; i <= x/2; i += 2)
		{
			if(odd[i] && odd[x-i])
			{
				break;
			}
		}
		printf("%d = %d + %d\n", x, i, x-i);
		scanf("%d", &x);
	}
	return 0;
}

 
