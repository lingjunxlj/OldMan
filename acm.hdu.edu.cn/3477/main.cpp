#include <cstdio>
#include <cmath>

double change(double a)
{
    if(a<0)
        return -a;
    else
        return a;
}

int main()
{
    int t;
    scanf("%d",&t);
    int o=1;
    while(t--)
    {
        double ua,u0,u1,t1;
        int n;
        scanf("%lf%lf%lf%lf%d",&ua,&u0,&u1,&t1,&n);
        double a;
        a=-(log((u1-ua)/(u0-ua)))/t1;
        double c;
        double l=0.0,r=9999999.9;
        double mid;
        printf("Case %d:\n",o++);
        while(n--)
        {
            int p;
            double s;
            scanf("%d%lf",&p,&s);
            if(p==0)
            {
                if(fabs(u0-ua)<0.0001)
                    printf("%.2lf\n",0);
                else
                    printf("%.2lf\n",(log((s-ua)/(u0-ua)))/(-a));
            }
            else
            {
                if(fabs(u0-ua)<0.0001)
                    printf("%.2lf\n",ua);
                else
                    printf("%.2lf\n",ua+(u0-ua)*exp((-a)*s));
            }
        }
        printf("\n");
    }
    return 0;
}
