#include <iostream>
using namespace std;
long long num1[801],num2[801];
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    int x,y=0;
    scanf("%d",&x);
    while (x--)
    {
        y++;
        int n;
        scanf("%d",&n);
        int i;
        long long sum=0;
        for (i=0;i<n;i++)
        scanf("%lld",&num1[i]);
        for (i=0;i<n;i++)
        scanf("%lld",&num2[i]);
        sort(num1,num1+n);
        sort(num2,num2+n,cmp);
        for (i=0;i<n;i++)
        sum+=(num1[i]*num2[i]);
        printf("Case #%d: %lld\n",y,sum);
    }

}
