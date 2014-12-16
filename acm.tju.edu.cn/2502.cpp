#include<iostream>
#include <stdlib.h>
using namespace std;
int main (void)
{
    long long x;
    cin>>x;
    while(x--)
    {
        long long a;
        cin>>a;
        long long j;
        for (j=0;j<=a;j++)
        {
            long long m=j;
            long long n=j;
            while (n)
            {
                  m+=n%10;
                  n/=10;
            }
            if (m==a) break;
        }
        if (j!=a+1) cout<<j<<endl;
        else cout<<'0'<<endl;
    }
    system("pause");   
}
