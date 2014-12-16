#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int MAX = 1001;
int x, n, primen = 0;
bool flag[MAX];
int phi[MAX], prime[MAX];
void Phi()
{
    int i, j;

    for (i = 2; i <= MAX; i++)
    {

       if (!flag[i])
       {
           prime[primen++] = i;
           phi[i] = i-1;
       }

       for (j = 0; j < primen && prime[j] * i <= MAX; j++)
       {
           flag[prime[j] * i] = true;

           if (i % prime[j] == 0)
           {
               phi[prime[j] * i] = phi[i] * prime[j];
               break;
           }

           else
            phi[prime[j] * i] = phi[i] * (prime[j]-1);
       }

   }

}
int main()
{
    Phi();

    int i, j;

    for (i = 2; i <= MAX; i++)
    phi[i] += phi[i - 1];

    scanf("%d", &x);

    for (j = 1; j <= x; j++)
    {
       scanf("%d", &n);
       printf("%d %d %d\n", j, n, phi[n] * 2 + 3);
    }

}
