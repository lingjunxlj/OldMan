#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void A( char s[])
{
     int len = strlen( s);
     int i;
     for( i=0; i < len/2 ;i++ )
     {
          char c = s[i];
          s[i] = s[len - 1 - i] ;
          s[len - 1 - i] = c;
     }
     return ;
}
void C( char s[] )
{
     char one = s[0];
     int i;
     for(  i = 0 ; i < strlen(s) - 1 ; i++)
     {
          s[i] = s[i+1];
     }
     s[ i ] = one;
     return ;
}
void M( char s[])
{
     for ( int i = 0 ; i < strlen(s); i++)
     {
         if(s[i] >= '0' && s[i] <= '8')
         s[i] = s[i] + 1;

         else if( s[i] == '9' )
         s[i] = '0';

         else
         continue;

     }
     return ;
}
void P( char s[])
{
     for ( int i = 0 ; i < strlen(s); i++)
     {
         if(s[i] >= '1' && s[i] <= '9')
         s[i]=s[i]-1;

         else if( s[i] == '0' )
         s[i] = '9';
         else
         continue;

     }
     return ;
}
void E( char s[])
{
    char temp[100];
    int tt = 0;
    int len = strlen(s);
    int i;
    if( len % 2 ==1)
    {

        for ( i= len / 2 + 1; i < len; i++)
        {
            temp[ tt++ ] = s[i];
        }
        temp[tt++] = s[ len/2 ];
        for ( i = 0 ;i < len/2 ; i++)
        {
            temp[ tt++ ] = s[i];
        }
        temp[tt] ='\0';
    }
    else
    {
        for ( i = len/2 ; i < len; i++)
        {
            temp[ tt++ ] = s[i];
        }

        for ( i = 0 ;i < len/2 ; i++)
        {
            temp[ tt++ ] = s[i];
        }
        temp[tt] = '\0';

     }
     strcpy( s,temp);
     return ;
}
void J(char s[])
{

    int len = strlen( s );
    char end = s[len - 1];
    int i;
    for( i = len - 1; i >= 1 ; i--)
    {
        s[i] = s[i-1];
    }
    s[0] = end;
    return ;
}
int main()
{
    int T;
    cin>> T;
    while(T--)
    {
        char steps[100];
        char s[100];
        cin>> steps>> s;
        int i;
        for( i = strlen(steps) - 1 ; i >= 0 ; i--)
        {

            if( steps[i] == 'A' )
            {     A(s);    }

            else if( steps[i] == 'J' )
            {     J(s);    }

            else if( steps[i] == 'M' )
            {     M(s);    }

            else if( steps[i] == 'P' )
            {     P(s);    }

            else if( steps[i] == 'E' )
            {     E(s);    }

            else if( steps[i] == 'C' )
            {     C(s);    }
        }
        cout<< s <<endl;
    }
}
