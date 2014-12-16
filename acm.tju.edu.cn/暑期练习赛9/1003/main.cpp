
#include <cstdio>
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
    long long n;
    long long f1, f0, tf1, tf0;
    int i;

    long long t;
    while (scanf("%lld", &n) != EOF)
    {
        long long sum;
        t = exp_mod(2, n, 10007);
        int M = 10007;
        int p = n;
        long long a1, a2, a3, a4, b1, b2, b3, b4;
        a1 = a2 = a3 = 1;
        a4 = 0;
        f1 = 1;
        f0 = 0;
        while (p>0) {
            if (p&1) {
                tf1 = (f1*a1+f0*a2)%M;
                tf0 = (f1*a3+f0*a4)%M;
                f1 = tf1;
                f0 = tf0;
            }
            b1 = (a1*a1+a2*a3)%M;
            b2 = (a1*a2+a2*a4)%M;
            b3 = (a1*a3+a3*a4)%M;
            b4 = (a2*a3+a4*a4)%M;
            a1 = b1;
            a2 = b2;
            a3 = b3;
            a4 = b4;
            p /= 2;
        }

        sum = t - (2*(f1));

        if (sum >= 0)
            printf("%lld\n", sum%10007);
        else
            printf("%lld\n", sum%10007 + 10007);

    }
}
