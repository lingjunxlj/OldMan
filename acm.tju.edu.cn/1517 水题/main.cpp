#include <stdio.h>
#include <algorithm>
using namespace std;
int main ()
{
    int n;
    while ( scanf ("%d", &n) && n )
    {
        int x;
        int current = n;
        int count = 0;

        for ( int i = 0; i < n; i++ )
        {
            scanf ("%d", &x);
            if ( n == 1 && x == 1 )
                break;
            if ( current == 0)
            {
                count++;
                continue;
            }
            if ( x < current )
            current = x;
            current--;
        }
        printf ("%d\n", count);
    }
}
