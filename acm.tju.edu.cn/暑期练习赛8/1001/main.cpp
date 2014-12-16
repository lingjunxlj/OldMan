#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
bool num[10000000];
const int MAXV = 10000000;
bool flag[MAXV/2];
int prime[MAXV/2];
int size;
void genPrime(int max)
{
    memset(flag, true, sizeof(flag));
    for(int i = 2; i <= max / 2; i++)
    {
        if(flag[i])
        {
            for(int j = i << 1 ; j <= max; j += i)
            {
                flag[j] = false;
            }
        }
    }
    for(int i = 2 ; i <= max; i++)
    {
        if(flag[i])
        {
            prime[size++] = i;
        }
    }
}

int main()
{
    freopen("a.txt","w",stdout);
    int n, i;
    genPrime(MAXV);

    for (i = 0; i <= 1000000000; i++)
    printf("%d   ",prime[i]);


    memset(num, true, sizeof(num));
    for (i = 0; i <= 1000000000; i++)
    {
        int n = prime[i];
        while (n <= 1000000000)
        {
            num[n] = 0;
            if (2*n < 1000000000)
            num[2*n] = 0;

            n=n*n;
        }
    }
    while (scanf("%d", &n) != EOF)
    {
        if (n < 8)
        printf("%d\n", n - 1);
        else
        {
            if (num[n] == 0)
            printf("1\n");
            else
            printf("%d\n", n - 1);
        }
    }
}
