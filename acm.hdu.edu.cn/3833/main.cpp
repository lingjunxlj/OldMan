#include <cstdio>
#include <cstring>
char hash[10010];
int num;
int bee;
int tot;
int n;
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{

		bee=0;
		tot=0;
		num=0;

		memset(hash, 0, sizeof(hash));

		scanf("%d",&n);
        int nn = n;
        while(nn--)
        {
            scanf("%d", &num);
            hash[num]=1;
            for (int j=1; j<num && num+j<=n; j++)
            {
                if (hash[num-j]+hash[num+j]==1)
                {
                    bee=1;
                    break;
                }
            }
            num=0;
        }
		if (bee)
			printf("Y\n");

		else
			printf("N\n");
	}
}
