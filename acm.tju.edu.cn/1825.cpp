#include<iostream>
using namespace std;
int main()
{
	double speed , weight , strength ;
	while ( cin >> speed >> weight >> strength )
	{
		int t = 0 ;
		if( speed == 0 && weight == 0 && strength == 0 )
		{
			break ;
		}
		if( speed <= 4.5 && weight >= 150 && strength >= 200 )
		{
			t++ ;
			cout << "Wide Receiver " ;
		}
		if( speed <= 6.0 && weight >= 300 && strength >= 500 )
		{
			t++ ;
			cout << "Lineman " ;
		}
		if( speed <= 5.0 && weight >= 200 && strength >= 300 )
		{
			t++ ;
			cout << "Quarterback " ;
		}
		if( t == 0 )
		{
			cout << "No positions" ;
		}
		cout << endl;
	}
	return 0 ;
}
