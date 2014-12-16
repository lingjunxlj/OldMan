#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
int i, j, n, max = 1, a[1010], b[1010];

while( cin >> n )
{
   for( i = 0; i < n; i++ )
    cin >> a[i];
   b[0] = 1;
   for( i = 1; i < n; i++ )
   {
    b[i] = 1;
   
    for( j = 0; j < i; j++ )
     if( a[j] < a[i] && b[j] + 1 > b[i] )
      b[i] = b[j] + 1;

     if( b[i] > max )
      max = b[i];
   }
   cout << max << endl;
}
system("pause");
return 0;
}
 
