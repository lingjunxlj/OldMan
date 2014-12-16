#include <cstdio>
#include <cmath>
struct s
{
    double vi;
    double ti;
}speed[10001];
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        int i;
        for (i=0;i<n;i++)
        scanf("%lf   %lf",&speed[i].vi,&speed[i].ti);
        double Min=99999999,time=0;
        for (i=0;i<n;i++)
        {
            if(speed[i].ti<0)
            continue;
            time=speed[i].ti+4500*3.6/speed[i].vi;
            if (time<Min)
            Min=time;
        }
        int d=ceil(Min);
        printf("%d\n",d);
    }
}

