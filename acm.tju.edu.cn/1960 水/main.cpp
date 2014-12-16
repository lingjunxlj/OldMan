#include <cstdio>
int main()
{
    double h , u , d , f ;
    int day ;
    double cha , dis ;
    while( scanf( "%lf %lf %lf %lf" , &h , &u, &d , &f ) != EOF )
    {
        if( h )
        {
            cha = ( u * f ) / 100.0 ;
            day = 0 ;
            dis = 0 ;
            while( 1 )
            {
                day ++ ;
                dis += u ;
                if( dis > h )
                    break ;
                dis -= d ;
                if( dis < 0 )
                    break ;
                u -= cha ;
                if( u < 0 )
                    u = 0 ;
            }
            if( dis < 0 )
                printf( "failure on day %d\n" , day ) ;
            else
                printf( "success on day %d\n" , day ) ;
        }
        else
            return 0 ;
    }
    return 0 ;
}
