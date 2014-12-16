#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXV = 40000000; //素数表范围
bool flag[MAXV+1]; //标志一个数是否为素数
int prime[6000000+1]; //素数表,下标从0开始
int size; //素数个数
void Prime()
{
    for (int i = 2; i * i < MAXV; i++)
    {
        if (flag[i]) continue;
        for (int j = i; j * j < MAXV; j++)
            flag[i*j] = 1;
    }
    for (int i = 2; i < MAXV; i++)
        if (!flag[i])
            prime[size++] = i;

}
void genPrime(unsigned int max)
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
    //freopen ("a.txt", "w", stdout);
    Prime();
    //printf("%d\n", size);
    for (int i = 0; i < size; i++)
        if (prime[i] >  30000000)
            printf("%d\n",prime[i]);
    return 0;
}
