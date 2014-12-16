#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXV = 10000000;
bool flag[MAXV+1];
int prime[MAXV+1];
int size;
void genPrime(int max)
{
    memset(flag, true, sizeof(flag));
    for(int i = 2; i <= max / 2; i++)
    {
        if(flag[i])
        {
            for(int j = i << 1 ; j <= max; j += i)
            {
                flag[j] = false;
            }
        }
    }
    for(int i = 2 ; i <= max; i++)
    {
        if(flag[i])
        {
            prime[size++] = i;
        }
    }
}
int euler(int num)
{
	int i, res = num;
	for (i = 0; prime[i] * prime[i] <= num;i++)
    {
		if (num % prime[i])
            continue;
		res -= res / prime[i];
		while (!(num % prime[i]))
			num /= prime[i];
	}
	if (num > 1)
        res -= res / num;
	return res;
}

int main()
{
    genPrime(MAXV);
    int n, t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        long long sum = 0;
        for (int i = 1; i <= n; i++)
            if (n%i == 0)
                sum += euler(n/i + 1);
        printf("%lld\n", sum);
    }

}
