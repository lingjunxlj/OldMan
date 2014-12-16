#include <cstdio>
#include <string>
long long store[23];
bool flag[23];
void calculate()
{
    long long i,mul=1;
    for(i=1;i<23;i++)
    {
        mul*=i;
        store[i]=mul;
    }
    store[0]=1;
}
int main()
{
    long long n,m,i;
    calculate();
    while(scanf("%lld %lld",&n,&m))
    {
        if(n==0&&m==0)
        break;
        memset(flag,0,sizeof(flag));
        if(n==0||m==0)
        printf("NO\n");
        else
        {
            int flagn=0,flagm=0;
            for(i=23;i>0;i--)
            {
                if(store[i]<=n && !flag[i])
                {
                    n-=store[i];
                    flag[i]=1;
                    if(n==0)
                    {
                        flagn=1;
                        break;
                    }
                    if(n<0)
                    break;
                }

            }
            for(i=23;i>0;i--)
            {
                if(store[i]<=m && !flag[i])
                {
                    m-=store[i];
                    flag[i]=1;
                    if(m==0)
                    {
                        flagm=1;
                        break;
                    }
                    if(m<0)
                    break;
                }
            }
            if(flagm==1&&flagn==1)
            printf("YES\n");
            else
            printf("NO\n");
        }
    }

}
