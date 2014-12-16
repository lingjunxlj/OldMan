#include <cstdio>

int gcd(long long a,long long b)
{
    if (b==0)
    return a;
    return gcd(b,a%b);
}
long long C(int n, int k)
{
	long long ret = 1;
	for (int i = 1; i <= k; ++i) {
		ret *= (n - i + 1);
		ret /= i;
	}
	return ret;
}

int main()
{
    long long n;
    while (scanf("%lld",&n)!=EOF)
    {
        long long s1=5*n-5,s2=5*n;
        long long A=C(5,3)*C(s1,2)+C(5,4)*C(s1,1)+C(5,5)*C(s1,0);
        long long B=C(s2,5);
        long long s=gcd(A*n,B);
        printf("%lld/%lld\n",A*n/s,B/s);
    }
}
