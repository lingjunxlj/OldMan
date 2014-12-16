#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
char s[1010];
int a[1010];
int main()
{
    while ( scanf("%s",s) != EOF )
    {
          char *t;
          int n = 1;
          memset ( a, 0, sizeof ( a ) );
          t = strtok ( s,"5" );
          a[0] = atoi ( t );
          while ( t = strtok ( NULL,"5" ) )
          {
                 a[ n ++ ] = atoi ( t );
          }
          sort(a, a + n);
          for ( int i = 0; i != n; ++ i )
          {
                printf(i ? " %d" : "%d",a[i]);
          }
          putchar ( '\n' );
    }
    return 0;
}
