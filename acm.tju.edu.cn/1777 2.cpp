#include<stdio.h>
#include<math.h>
int main()
{
    long x,y,k,i;
    long double p,t,z;
    while(scanf("%d",&x)&&x!=0)
    {
        y=(x-1960)/10+2;
        z=pow(2,y);
        for(i=1;;i++)
        {
            p=i;
            t=log10(p)/log10(2);
            z=z-t;
            if(z<0) 
            {
                k=p-1;
                break;
            }
        }
        printf("%d\n",k);
    }
}

