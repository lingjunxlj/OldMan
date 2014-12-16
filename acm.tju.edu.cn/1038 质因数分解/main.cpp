#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std ;
const int MaxSize=400000 ;
bool pri[MaxSize] ;
int prime[MaxSize], pcnt ;
map <int, int> ans ;

void Prime()
{
    int i, j ;
    for( i = 0; i < MaxSize; ++i )
        pri[i] = true ;
    for( i = 2; i < MaxSize; ++i )
    {
        if( !pri[i] )
            continue ;
        for( j = i * 2; j < MaxSize; j += i )
            pri[j] = false ;
    }
    pcnt = 0 ;
    for( i = 2; i < MaxSize; ++i )
    {
        if( pri[i] )
        {
            prime[pcnt++] = i ;
        }
    }
}
void fact( long long num )
{
    long long i ;
    ans.clear() ;
    for( i=0; num!=1; ++i )
    {
        while( num%prime[i] == 0 )
        {
            ++ans[prime[i]] ;
            num /= prime[i] ;
        }
    }
}
int main()
{
    Prime() ;
    long long i, base, exp, temp ;
    string str, tstr ;
    while( getline(cin, str) )
    {
        if( str == "0" )
            break ;
        long long num = 1 ;
        stringstream ss(str) ;
        while( ss >> base >> exp )
        {
            temp = 1 ;
            for( i=0; i<exp; ++i )
                temp *= base ;
            num *= temp ;
        }
        fact( num-1 ) ;
        int flag = 0 ;
        map<int,int>::reverse_iterator it ;
        for( it=ans.rbegin(); it!=ans.rend(); ++it )
        {
            if( flag )
            printf(" ") ;
            ++flag ;
            printf("%d %d", it->first, it->second ) ;
        }
        printf("\n") ;
    }
}
