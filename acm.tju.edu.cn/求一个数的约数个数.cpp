#include<stdio.h>
#define that 31640

struct factor    {
    int d;
    int m;
} f[35];

bool prime[that]={1,1,0};
int p;

int main()    {
    int i,j,k,l,n,t,rst,sum;
    for(i=2;i<=178;i++)    {
        if(prime[i]==0)    {
            j=2*i;
            while(j<that)    {
                prime[j]=1;
                j+=i;
            }
        }
    }
    while(scanf("%d",&n)!=EOF)    {
        t=n;
        p=0;sum=0;
        for(i=2;i<that;i++)    {
            if(prime[i]==0 && n%i==0)    {
                f[p].d=i;
                f[p].m=0;
                while(n%i==0)    {
                    n=n/i;
                    f[p].m++;
                }
                sum+=f[p].m;
                p++;
                if(n==1)    break;
            }
        }
        if(n!=1)    {
            rst=2;
            for(i=0;i<p;i++)    rst*=f[i].m+1;
            printf("There are %d divisors of %d.\n",rst,t);
            continue;
        }
        rst=1;
        for(i=0;i<p;i++)    {
            rst*=(f[i].m+1);
        }
        printf("There are %d divisors of %d.\n",rst,t);
    }
    
}
