#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int vst[1010][1010];
main()
{
	int t, tt = 0;
	int sum, n, i, j, a;
	bool flag;

	scanf ( "%d", &t );
	while( t -- )
	{
		scanf ( "%d", &n );
		memset ( vst, 0, sizeof ( vst ) );
		vst[0][0] = 1;
		flag = false;
		sum = 0;
		while( n -- )
		{
			scanf ( "%d", &a );
			if ( a == 0 )	flag = true;
			for ( i = min( sum, 1000 ); i >= 0; i -- )
				for ( j = min( sum - i, 1000 ); j >= 0; j -- )
					if ( vst[i][j] )
					{
						if ( i + a <= 1000 )
                            vst[ i + a ][j] = 1;
						if ( j + a <= 1000 )
                            vst[i][ j + a ] = 1;
					}
			sum += a;
		}

		for ( i = sum / 2; i > 0; i -- )
			if ( vst[i][i] )
				break;
		if ( flag || i )
			printf( "Case %d: %d\n", ++ tt, i );
		else
			printf( "Case %d: -1\n", ++ tt );
	}

	return 0;
}
