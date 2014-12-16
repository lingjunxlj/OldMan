#include <cstdio>
int main()
{
    long long n;
    while (scanf("%lld", &n), n)
    {
        long long sum = 1, Min=0;
        int t = 20;
        while (t--)
        {

            n%sum;
            if (n % sum == 0 )
            {
                if ( sum > Min)
                {
                    Min = sum;
                }

            }
             sum = sum*10+1;
        }

        printf("%lld\n",n/Min);
    }
}
