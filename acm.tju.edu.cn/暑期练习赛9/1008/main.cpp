#include <iostream>
#include <cstdio>
using namespace std;
long long exp_mod(long long a, long long b, int mod)
{
	long long res = 1;
	while (b) {
		if (b & 1) {
			res *= a; res %= mod;
		}
		a *= a; a %= mod;
		b >>= 1;
	}
	return res;
}
int main()
{
    int t,x=0, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        x++;

        long long sum;
        sum = exp_mod(2, n , 10007);
        printf("%lld----sum\n",sum);
        sum = sum/6+10/6;

        printf("Case #%d: %lld\n",x, sum%10007);
    }
}
