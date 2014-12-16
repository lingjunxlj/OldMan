#include<cstdio>
#include<string>
int main()
{
	char str[80];
	int count;
	int i, j, k;
	int len;
	scanf("%s", str);
	while(str[0] != '*')
	{
		len = strlen(str);
		for(i = 0; i < len; i++)
		{
			count = 0;
			k = 0;
			for(j = i + 1; j < len; j++)
			{
				if(str[j] == str[k])
					count++;

				if(count>=2)
					break;

                k++;
			}
			if(count >= 2)
				break;
		}

		if(count >= 2)
			printf("%s is NOT surprising.\n", str);

		else
			printf("%s is surprising.\n", str);

		scanf("%s", str);
	}
	return 0;
}
