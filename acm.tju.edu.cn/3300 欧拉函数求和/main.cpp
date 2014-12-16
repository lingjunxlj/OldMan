#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long f[3000005];
bool ok[3000005];
int sum = 0;
int num[10000];
void cal()
{
    int i, j;
    f[1] = 0;
    for (i = 2; i <= 3000000; i++)
    {
        if (ok[i])
            f[i] = i - 1;
        else
            for (j = 1; j <= sum; j++)
            {
                if (i % num[j] == 0)
                {
                    if ((i / num[j]) % num[j] == 0)
                        f[i] = f[i / num[j]] * num[j];
                    else
                        f[i] = f[i / num[j]] * (num[j]-1);
                    break;
                }
            }
    }
    for (i = 2; i <= 3000000; i++)
        f[i] += f[i - 1];
}

void start()
{
    int i, j;
    memset(ok, 1, sizeof(ok));
    for (i = 2; i * i <= 3000005; i++)
    {
        if (ok[i])
            for (j = i * i; j <= 3000005; j += i)
                ok[j] = 0;
    }

    for (i = 2; i <= sqrt(3000005); i++)
    {
        if (ok[i])
            {
                sum++;
                num[sum] = i;
            }
    }
}
int main()
{
    int a,b;
    int i;
    int ans = 0;
    start();
    cal();
    while (scanf("%d %d", &a, &b) != EOF)
        printf("%lld\n", f[b] - f[a - 1]);
}
/*
（转）在程序中利用欧拉函数如下性质，可以快速求出欧拉函数的值(a为N的质因素)
(1) 若(N%a==0 && (N/a)%a==0) 则有:E(N)=E(N/a)*a;
(2) 若(N%a==0 && (N/a)%a!=0) 则有:E(N)=E(N/a)*(a-1);
*/
