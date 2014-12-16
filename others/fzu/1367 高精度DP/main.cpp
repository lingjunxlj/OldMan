#include<stdio.h>
#include<math.h>
int a,b;
double n[110][110];
double dp(int e,int h)
{
    if(e==b)
    {
        if(h>=0&&h<=a)return n[e][h]=1.0;
        else return 0.0;
    }
    else if(e<b&&h>=0&&h<=a)
    {
        if(n[e][h]==-1)
        return n[e][h]=dp(e+1,h-1)+dp(e+1,h)+dp(e+1,h+1);

        else return n[e][h];
    }
    else return 0.0;
}

int main()
{
    int i,j,k;
    double d;
    while(scanf("%d %d",&a,&b)!=EOF)
    {
        if(a==0)printf("100.00000\n");
        else
        {
        k=a>b?a:b;
        for(i=0;i<=k;i++)
        {
            for(j=0;j<=k;j++)
            {
                n[i][j]=-1;
            }
        }
        d=0.0;
        for(i=0;i<=a;i++)
        {
            d=d+dp(1,i);
        }
        printf("%.5lf\n",(d/pow((double)a+1,(double)b))*100);
        }
    }
    return 0;
}
