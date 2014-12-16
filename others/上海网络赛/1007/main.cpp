#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define M 100001
long long c[M];
bool num[M];
int n;
int LowBit(int x)
{
    return x&(-x);
}

void update(int i,long long val)
{
    while(i <= n)
    {
        c[i]+=val;
        i+=LowBit(i);
    }
}

long long getSum(int x)
{
    long long sum=0;
    while(x > 0)
    {
        sum+=c[x];
        x-=LowBit(x);
    }
    return sum;
}
int main()
{
	int  x = 1, m;
	while(scanf("%d",&n) != EOF)
	{
	    memset(c, 0, sizeof(c));
	    memset(num, 0, sizeof(num));
	    for (int i = 1; i <= n; i++)
	    {
	        long long temp;
	        scanf("%I64d", &temp);
	        update(i, temp);
	    }
        printf("Case #%d:\n", x++);


		scanf("%d", &m);
		while(m--)
		{
			int fg;
			scanf("%d", &fg);
			if (fg == 0)
			{
			    int a, b;
			    scanf("%d %d", &a, &b);
			    for (int i = a; i <= b; i++)
			    {
			        if (num[i] == 1)
                        continue;
			        long long zero = getSum(i) - getSum(i - 1);
			        if (zero <= 1)
			        {
			            num[i] = 1;
			            continue;
			        }
                    update(i,-(zero - (long long)floor((double)sqrt((double)zero))));
			    }
			}
			if (fg == 1)
            {
                int a, b;
			    scanf("%d %d", &a, &b);
			    printf("%I64d\n",getSum(b) - getSum(a - 1));
			    //printf("1\n");

            }
		}
		printf("\n");
	}
	return 0;
}
