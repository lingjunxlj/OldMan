#include <stdio.h>
#include <math.h>

typedef unsigned long ul;
void slove( ul N )
{
    ul a = (ul)(sqrt(8*N+1)-1)/2 ,
       b = N - a * (a+1) / 2;
    printf( "TERM %lu IS %lu/%lu\n" , N , 
        !b?(a&1?1:a):(a&1?b:a+2-b) ,
        !b?(a&1?a:1):(a&1?a+2-b:b) );
}
int main()
{
    ul N ;
    while( 1 == ( scanf( "%lu" , &N ) ) && N >= 1 )
        slove( N );
    return 0;
}
