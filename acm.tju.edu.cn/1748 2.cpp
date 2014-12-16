#include<iostream>
using namespace std;

int main()
{
    string s1, s2;
    while( cin >> s1 >> s2 )
    {
        if( s1 == "0" && s2 == "0" )break;
        int n1, n2;
        n1 = s1[s1.length()-1]-'0';
        n2 = s2[s2.length()-1]-'0';
        
        if( s2.length() > 1 )
        {
                n2 += ( 10 * ( s2[s2.length()-2 ] - '0' ) );    
        } 
        
        if( n1 == 0 )
        {
                cout << "0" << endl;
                continue;    
        }    
        
        if( n2 == 0 && s2.length() == 1 ) 
        {
                cout << "1" << endl;
                continue;    
        }
        
        int result = 1;
        int up = ((n2%4 == 0)? 4: (n2%4) );
        for( int j = 1; j <= up; j++ )
        {
              result *= n1;    
        }    
        result%=10;
        cout << result << endl;
    }    
}
