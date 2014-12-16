#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int mod = 1000000007;
const int Max = 3;
struct Mat
{
    long long  Matrix[Max][Max];
}e, init;

Mat mul(Mat a, Mat b)
{
    int i, j, k;
    Mat c;
    for(i=0; i<Max; i++)
        for(j=0; j<Max; j++)
            c.Matrix[i][j] = 0;

    for(i=0; i<Max; i++)
    {
        for(k=0; k<Max; k++)
        {
            if(a.Matrix[i][k])
            {
                for(j=0; j<Max; j++)
                {
                    if(b.Matrix[k][j])
                    {
                        c.Matrix[i][j] += a.Matrix[i][k]*b.Matrix[k][j];
                        if(c.Matrix[i][j] >= mod)
                            c.Matrix[i][j] %= mod;
                        if (c.Matrix[i][j] < 0)
                            c.Matrix[i][j] += mod;
                    }
                }
            }
        }
    }
    return c;
}

Mat exs_mod(long long n)
{
    Mat p = e, q = init;
    while(n)
    {
        if(n&1)
            p = mul(p, q);
        n >>= 1;
        q = mul(q, q);
    }
    return p;
}

int main()
{
    int t, i, j;
    long long l, r, ans;
    int p[] = {0, 2, 15, 104};
    scanf("%d",&t);
    for(i=0; i<Max; i++)
    {
        for(j=0; j<Max; j++)
        {
            e.Matrix[i][j] = (i==j);

            init.Matrix[i][j] = 0;
        }
    }
    init.Matrix[0][0] = 8;
    init.Matrix[0][1] = -8;
    init.Matrix[0][2] = 1;
    init.Matrix[1][0] = init.Matrix[2][1] = 1;

    while(t--)
    {
        scanf("%I64d %I64d", &l, &r);
        long long num1=0, num2=0;
        if(l <= 3)
        {
            num1 += p[l-1];
        }
        else
        {
            Mat temp1 = exs_mod(l-4);
            num1 = (104*temp1.Matrix[0][0]%mod + 15*temp1.Matrix[0][1]%mod + 2*temp1.Matrix[0][2]%mod)%mod;
        }
        if(r <= 3)
        {
            num2 += p[r];
            printf("%I64d\n", (num2 - num1));
            continue;
        }
        else
        {
            Mat temp2 = exs_mod(r-3);
            long long m;
            for(i=0; i<3; i++)
            {
                m = (p[3-i]*temp2.Matrix[0][i])%mod;
                //printf("%lld\n", temp2.Matrix[0][i]);
                //printf("m == %lld\n", m);

                num2 = (num2 + m)%mod;
                if(num2 < 0)
                    num2 += mod;
            }
            ans = (num2-num1)%mod;
            if(ans < 0)
                ans += mod;
            printf("%I64d\n", ans);
        }
    }
    return 0;
}
