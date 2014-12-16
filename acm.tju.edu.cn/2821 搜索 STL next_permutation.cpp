#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main ()
{
    int n;
    while ( cin >> n && n ) 
    {
        int a [20];
        for ( int i = 0; i < n; i++ )
        cin >> a [i];
        int binary [20] = {0};
        int minimum = 99999;
        for ( int i = 0; i < ceil (n / 2); i++ ) 
        {
            binary [i] = 1;
            sort (binary, binary + n);
            do 
            {
                int team1 = 0;
                int team2 = 0;
                for ( int j = 0; j < n; j++ ) 
                {
                    if ( binary [j] )
                    team1 += a [j];
                    else
                    team2 += a [j];
                }

                int difference;
                if ( team1 > team2 )
                difference = team1 - team2;
                else
                difference = team2 - team1;
                if ( minimum > difference )
                minimum = difference;
            } while ( next_permutation (binary, binary + n) );
        }

        cout << minimum << endl;
    }

    return 0;
}
