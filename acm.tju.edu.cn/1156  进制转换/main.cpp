#include <cstdio>
#include <string>
char str[200];
int main()
{
    long long n;
    while (scanf("%lld",&n),n)
    {
        scanf("%s",str);
        int len=strlen(str);
        long long sum=0;
        long long x=1;
        int i=len-1;
        int sum1=0;
        while (i>=0)
        {
            sum=sum+(str[i]-'0')*x;
            sum1=sum1+(str[i]-'0');
            x*=n;
            i--;
        }
        if (sum%sum1==0)
        printf("yes\n");
        else
        printf("no\n");
    }
}


