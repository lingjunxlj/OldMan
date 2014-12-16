#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
bool prime[50000];
int pp[10000];
int main()
{
    int i, j, num, T, n, sum, t, e = 1, ll;
    memset(prime, true, sizeof(prime));
    prime[0] = false; prime[1] = false;

    for(i = 2; i < 50000; i ++)
        for(j = 2; i*j < 50000; j ++)
            prime[i*j]= false;

    num = 0;
    for(i = 0; i < 50000; i ++)
        if(prime[i] == true)
            pp[num++] = i;

    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum = 1;
        ll = (int)sqrt(n*1.0);
        for(i = 0; i < num; i ++)
        {
            if(pp[i] > ll +1)
                break;

            t = 0;
            while(n % pp[i] == 0)
            {
                t++;
                n/= pp[i];
            }
            sum *= (t*2+1);
        }
        if(n > 1)
            sum *= 3;

        printf("Scenario #%d:\n",e++);
        printf("%d\n\n",(sum+1)/2);
    }
    return 0;
}
