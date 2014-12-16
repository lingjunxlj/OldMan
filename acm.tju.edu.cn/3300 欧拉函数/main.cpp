#include <iostream>
#include <cstdio>
#include <cstring>
#define N 3000002
int prime[N/3],phi[N];
bool visit[N];
using namespace std;
void get_prime()
{
    int i, j, size = 0;
    memset(visit, false, sizeof(visit));
    for(i = 2; i < N; i++)
    {
        if(!visit[i])
        {
            prime[size++] = i;
            phi[i]=i-1;
        }
        for(j = 0; j < size && prime[j] * i < N; j++)
        {
            visit[i * prime[j]] = true;
            if (i % prime[j] == 0 )
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
        }
    }
}
int main()
{
    int i, j, k, m;
    long long n;
    get_prime();
    while(scanf("%d %d", &i, &j) != EOF)
    {
        n = 0;
        for(k = i; k <= j; k++)
            n += phi[k];
        printf("%lld\n", n);
    }
}
