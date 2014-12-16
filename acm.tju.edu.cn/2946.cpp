#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
    char a [100];
    gets (a);
    int length = strlen (a);
    printf ("..#..");
    for ( int i = 2; i <= length; i++ ) 
    {
        char ch = '#';
        if ( i % 3 == 0 )
        ch = '*';
        printf (".%c..", ch);
    }
    printf ("\n");
    printf (".#.#.");
    for ( int i = 2; i <= length; i++ ) 
    {
        char ch = '#';
        if ( i % 3 == 0 )
        ch = '*';
        printf ("%c.%c.", ch, ch);
    }
    printf ("\n");
    printf ("#.%c.#", a [0]);
    for ( int i = 2; i <= length; i++ ) 
    {
        char ch = '#';
        if ( (i + 1 <= length && (i + 1) % 3 == 0) || i % 3 == 0 )
        ch = '*';
        printf (".%c.%c", a [i - 1], ch);
    }
    printf ("\n");
    printf (".#.#.");
    for ( int i = 2; i <= length; i++ ) 
    {
        char ch = '#';
        if ( i % 3 == 0 )
        ch = '*';
        printf ("%c.%c.", ch, ch);
    }
    printf ("\n");
    printf ("..#..");
    for ( int i = 2; i <= length; i++ ) {
        char ch = '#';
        if ( i % 3 == 0 )
        ch = '*';
        printf (".%c..", ch);
    }
    printf ("\n");
    system("pause");
    return 0;
}
