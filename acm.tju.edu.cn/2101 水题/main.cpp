#include<stdio.h>
#include<math.h>
int main()
{
    int i, j;
    double z, x, y;
    while( 1 )
    {
        int s[2] = {0};
        for( i = 0; i < 2; i++ )
        {
            for( j = 0; j < 3; j++ )
            {
                scanf("%lf %lf", &x, &y);
                if( x == -100 ) return 0;
                z = sqrt( x * x + y * y );
                if( z <= 3 )
                s[i] += 100;
                else if(z <= 6 )
                s[i] += 80;
                else if( z <= 9 )
                s[i] += 60;
                else if( z <= 12 )
                s[i] += 40;
                else if( z <= 15 )
                s[i] += 20;
                else
                s[i] += 0;
            }
        }
        if( s[0] > s[1] )
        printf("SCORE: %d to %d, PLAYER 1 WINS.\n", s[0], s[1]);
        else if( s[0] < s[1] )
        printf("SCORE: %d to %d, PLAYER 2 WINS.\n", s[0], s[1]);
        else
        printf("SCORE: %d to %d, TIE.\n", s[0], s[1]);
    }
}
