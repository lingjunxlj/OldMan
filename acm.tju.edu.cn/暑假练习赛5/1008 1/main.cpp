#include <iostream>
#include <cstdio>
using namespace std;
long long num[10001];
int main()
{
    int n;
    while (cin>>n)
    {
        if (n <1)
        break;
        int i,j;
        int sum=0;
        for (i=0;i<(1<<n)%9997;i++)
        {

            for (j=0;j<=n-3;j++)
            if (i ^(5<<j) < i )
            sum++;
        }
        printf("%d\n",sum%9997);
    }
}
