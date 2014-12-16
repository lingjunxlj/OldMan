#include <cstdio>
#include <cmath>
int main()
{
    double n;
    while (scanf("%lf",&n),n)
    {
        double p,b;
        long long Floor,Ceil;
        if (n>0)
        {
            for (p=32;p>0;p--)
            {
                b=pow(n,1.0/p);
                Floor=b;
                Ceil=Floor+1;
                if (b-Floor<=1e-12||Ceil-b<=1e-12)
                break;
            }
            printf("%.0lf\n",p);
        }
        else
        {
            n=-n;
            for (p=31;p>0;p-=2)
            {
                b=pow(n,1.0/p);
                Floor=b;
                Ceil=Floor+1;
                if (b-Floor<=1e-12||Ceil-b<=1e-12)
                break;
            }
            printf("%.0lf\n",p);
        }
    }
}
