
#include <cstdio>
#include <cstring>
#include <cmath>


const int Max = 52;
__int64 mod, x;
struct Mat
{
    __int64 Matrix[Max][Max];
}e, init;
__int64 c[Max][Max];

Mat mul(Mat a, Mat b)
{
    int i, j, k;
    Mat c;
    for(i=0; i<=x+1; ++i)
    for(j=0; j<=x+1; ++j)
        c.Matrix[i][j] = 0;

    for(i=0; i<=x+1; i++)
    {
        for(k=0; k<=x+1; k++)
        {
            if(a.Matrix[i][k])  //将k提前，  先判a.Matrix[i][k]是否为0  达到剪枝的效果
            {
                for(j=0; j<=x+1; j++)
                {
                    c.Matrix[i][j] += a.Matrix[i][k]*b.Matrix[k][j];
                    if(c.Matrix[i][j] >= mod)
                        c.Matrix[i][j] %= mod;
                }
            }
        }
    }
    return c;
}

Mat exs_mod(__int64 n)
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

void com()  //求组合数
{
    int i, j;
    for(i=0; i<=x; i++)
        c[i][0] = c[i][i] = 1;
    for(i=2; i<=x; i++)
    {
        for(j=1; j<i; j++)
        {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]);  //这是组合数的一个性质
            if(c[i][j] >= mod)
                c[i][j] %= mod;
        }
    }
   // cout<<"yes"<<endl;
}

int main()
{
    int i, j;
    __int64 n;
    for(i=0; i<Max; ++i)
        for(j=0; j<Max; ++j)
            e.Matrix[i][j] = (i == j);

    while(scanf("%I64d %I64d %I64d",&n, &x, &mod))
    {
        if(n==-1 && x== -1 && mod== -1)
            break;

        memset(c, 0, sizeof(c));
        memset(init.Matrix, 0, sizeof(init.Matrix));
        com();
        for(j=0; j<=x; j++)
        {
            for(i=0; i<=j; i++)
            {
                init.Matrix[i][j] = c[j][i] * x;
                if(init.Matrix[i][j] >= mod)
                    init.Matrix[i][j] %= mod;
            }
        }
        for(i=0; i<=x; i++)
        {
            init.Matrix[i][x+1] = c[x][i] * x;
            if(init.Matrix[i][x+1] >= mod)
                    init.Matrix[i][x+1] %= mod;
        }
        init.Matrix[x+1][x+1] = 1;

        Mat ans = exs_mod(n);
        printf("%I64d\n", ans.Matrix[0][x+1]);
    }
    return 0;
}
