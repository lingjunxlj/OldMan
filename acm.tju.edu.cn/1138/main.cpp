#include <cstdio>
long long C(long long n, long long r)
{
	long long i, j, s = 1;
	for(i = 0, j = 1; i < r; i++)
		for(s *= n - i; j <= r && !(s % j); j++) s /= j;
	return s;
}
int main()
{
    long long n,k;
    while (scanf("%lld %lld",&n,&k)!=EOF)
    {
        if (n==0&&k==0)
        break;
        if(k>n/2)
        k=n-k;
        long long sum=C(n,k);
        printf("%lld\n",sum);
    }
}
