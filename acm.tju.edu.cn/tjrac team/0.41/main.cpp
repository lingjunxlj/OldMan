#include <iostream>
#include <cstdio>
using namespace std;
const int MAXV = 10000000;
bool flag[MAXV+1];
int prime[MAXV+1];
long long size;
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
long long exp_mod(long long a, long long b)
{
	long long res = 1;
	while (b) {
		if (b & 1) {
			res *= a;
		}
		a *= a;
		b >>= 1;
	}
	return res;
}
long long euler(long long num)
{
	long long i, res = num;
	for (i = 0; prime[i] * prime[i] <= num;
		i++) {
		if (num % prime[i]) continue;
		res -= res / prime[i];
		while (!(num % prime[i]))
			num /= prime[i];
	}
	if (num > 1) res -= res / num;
	return res;
}
int main()
{
    genPrime(MAXV);
    int n,m;
    while (1)
    {
        scanf("%d %d",&n,&m);
        if (n==0&&m==0)
        break;
        long long sum;
        sum=exp_mod(n,m);
        printf("%lld\n",euler(sum)%201004);
    }
}



