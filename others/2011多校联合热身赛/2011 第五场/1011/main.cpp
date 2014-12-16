#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double x[10005];
double y[10005];

int main()
{
    int n, p, i, j;
    double ans;
    while(scanf("%d %d",&p,&n)!=EOF)
    {
        if(p == 1)
        {
            double sdx, temp=0, sum=0, avex;
            for(i=0; i<n; i++)
            {
                scanf("%lf",&x[i]);
                sum += x[i];
            }
            avex = sum/n;
            for(i=0; i<n; i++)
            {
                temp += (x[i]-avex)*(x[i]-avex);
            }
            printf("%.2lf",(x[0]-avex)/sqrt(temp/n));
            for(i=1; i<n; i++)
                printf(" %.2lf",(x[i]-avex)/sqrt(temp/n));
            printf("\n");
        }

        else if(p==2)
        {
            double sdx, temp=0, sum=0, avex, sam;
            scanf("%lf",&sam);
            for(i=0; i<n; i++)
            {
                scanf("%lf",&x[i]);
                sum += x[i];
            }
            avex = sum/n;
            for(i=0; i<n; i++)
            {
                temp += (x[i]-avex)*(x[i]-avex);
            }
            sdx = sqrt(temp/(n-1));
            double sex = sdx/(sqrt(double (n)));
            //if(sam-avex < 1e-8 && sam-avex > -1e-8)
                //printf("%.2lf\n",(sam-avex));
            //else
            //{
            ans = (avex-sam)/(sex);
                printf("%.2lf\n",ans);
            //}
        }
        else if(p == 3)
        {
            double sdx, temp=0, sum=0, avex, sdy, avey, k=0;
            for(i=0; i<n; i++)
            {
                scanf("%lf",&x[i]);
                sum += x[i];
            }
            avex = sum/n;
            for(i=0; i<n; i++)
            {
                temp += (x[i]-avex)*(x[i]-avex);
            }
            sdx = sqrt(temp/n);

            sum = 0;
            for(i=0; i<n; i++)
            {
                scanf("%lf",&y[i]);
                sum += y[i];
            }
            avey = sum/n;
            for(i=0; i<n; i++)
            {
                k += (y[i]-avey)*(y[i]-avey);
            }
            sdy = sqrt(k/n);
            temp = 0;
            for(i=0; i<n; i++)
            {
                temp += (x[i]-avex)*(y[i]-avey);
            }
            double rxy = temp/(n*sdx*sdy);
            printf("%.2lf\n",rxy);
        }
        else if(p == 4)
        {
            double sdx, temp=0, z, sum=0, avex, sdy, avey, k=0;
            for(i=0; i<n; i++)
            {
                scanf("%lf",&x[i]);
                sum += x[i];
            }
            avex = sum/n;
            for(i=0; i<n; i++)
            {
                temp += (x[i]-avex)*(x[i]-avex);
            }
            sdx = sqrt(temp/n);
            sum = 0;
            for(i=0; i<n; i++)
            {
                scanf("%lf",&y[i]);
                sum += y[i];
            }
            avey = sum/n;
            for(i=0; i<n; i++)
            {
                k += (y[i]-avey)*(y[i]-avey);
            }
            sdy = sqrt((k)/n);
            temp = 0;
            for(i=0; i<n; i++)
            {
                temp += (x[i]-avex)*(y[i]-avey);
            }
            double rxy = temp/(n*sdx*sdy);
            double b = rxy*(sdy/sdx);
            double a = (avey - b*avex);
            printf("%.2lf %.2lf\n",a,b);
        }
    }
    return 0;
}
