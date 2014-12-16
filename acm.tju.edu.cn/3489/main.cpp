#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        int num[50],m,i;
        scanf("%d",&m);
        for (i=0;i<m;i++)
        scanf("%d",&num[i]);
        sort(num,num+m);
        long long sum=1;
        for (i=0;i<m;i++)
        sum=sum*(num[i]-i)%1000000007;
        printf("%lld\n",sum);
    }
}
