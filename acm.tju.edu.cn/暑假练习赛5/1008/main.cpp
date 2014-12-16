#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    long long n;
    while (scanf("%I64d", &n))
    {
        if (n == 0 || n == -1)
        break;

        if (n == 1)
        {
            printf("2\n");
            continue;
        }

        if (n == 2)
        {
             printf("4\n");
             continue;
        }

        long long i;
        long long sum1 = 1;
        long long sum2;
        long long sum3;
        long long sum = 1;
        {
            long long j;
            for (j = 1; j<=n-3;j++)
            {
               sum1 =sum1*2;
               sum1 = sum1 % 9997;
            }

            //printf("%d----sum1\n",sum1);
            sum2 =(n-3+1)%9997;
            //printf("%d----sum2\n",sum2);
            sum3 =(sum1%9997)*(sum2%9997)%9997;
            printf("%d----sum3\n",sum3);

        }
        for (i = 1; i<=n; i++)
        {
            sum = sum *2;
            sum = sum % 9997;
        }

        //printf("%d----sum\n",sum);

        sum=sum-sum3;

        if (sum>0)
        printf("%I64d\n",sum%9997);
        else
        printf("%I64d\n",-sum%9997);

    }
}
