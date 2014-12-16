#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int MaxSize = 1000001;
bool is_prime[MaxSize];
int prime[MaxSize];
long long num, geshu;
int main()
{
    int i, j ;
    for( i = 2; i < MaxSize; i++)
    is_prime[i] = true ;
    int up = MaxSize/2 ;
    for( i = 2; i <= up; i++){
        if( !is_prime[i]) continue;
        for( j = i + i; j < MaxSize; j += i)
            is_prime[j] = false ;
    }
    j = 0;
    for( i = 2; i < MaxSize; i++)
        if( is_prime[i])
            prime[j++] = i ;
    geshu = j ;
    while( scanf("%lld", &num))
    {
        if (num < 0) break;
        long long i ;
        for( i=0; i < geshu; i++){
            while( num%prime[i] == 0 ){
                printf("    %d\n", prime[i]) ;
                num /= prime[i] ;
            }
            if( num == 1 )
            break ;
        }
        if( num == 1 ){
            printf("\n");
            continue;
        }
        long long up = (long long)sqrt( (double)num )+1 ;
        for( i = prime[geshu-1] + 1; i < up; i++)
            while( num%i == 0 ){
                printf("    %lld\n", i) ;
                num /= i ;
            }
        if( i >= up )
            printf("    %lld\n", num ) ;
        printf("\n");
    }
}
