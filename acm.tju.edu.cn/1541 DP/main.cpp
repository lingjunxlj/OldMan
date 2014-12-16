#include <iostream>
#include <cstring>
using namespace std;

char input [1000000];
long long dp [1000000];

bool duet (int i)
{
    if ( input [i - 1] == '0' )
        return false;

	int num = (input [i - 1] - '0') * 10 + (input [i] - '0');

	if ( num >= 1 && num <= 26 )
		return true;
	return false;
}

int main()
{

    while ( scanf ("%s", input) && strcmp (input, "0") )
    {
        dp [0] = 1;

		int length = strlen (input);
		long long x = 0;

		for ( int i = 1; i < length; i++ )
		{
			if ( duet (i) )
			{
				if ( i >= 2 )
					x = dp [i - 1] - dp [i - 2];

				if ( input [i] == '0' )
					dp [i] = dp [i - 1] - x;
				else
					dp [i] = dp [i - 1] * 2 - x;
			}
			else
				dp [i] = dp [i - 1];
		}

		printf ("%lld\n", dp[length - 1]);
	}

	return 0;
}
