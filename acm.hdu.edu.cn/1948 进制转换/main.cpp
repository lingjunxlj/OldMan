#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[30];
    int inta[71];
    int b1, b2, len, i, j, sum, m, temp;
    while ( cin >> str >> b1 >> b2 && str && b1 && b2)
    {
         inta['0'] = 0;
         inta['1'] = 1;
         inta['2'] = 2;
         inta['3'] = 3;
         inta['4'] = 4;
         inta['5'] = 5;
         inta['6'] = 6;
         inta['7'] = 7;
         inta['8'] = 8;
         inta['9'] = 9;
         inta['A'] = 10;
         inta['B'] = 11;
         inta['C'] = 12;
         inta['D'] = 13;
         inta['E'] = 14;
         inta['F'] = 15;

         len = strlen(str);
         int k=1;
         i = len-1;
         sum = 0;
         while ( i >=0 )
         {
                sum += inta[str[i]] * k;
                k = k * b1;
                i--;
         }
         i=0;
         while ( sum > 0 )
         {
                temp = sum % b2;
                if ( temp >= 10 )
                {
                       str[i++] = (char)(temp - 10 +'A');
                }
                else
                       str[i++] = (char)( temp + '0' );
                sum /= b2;
         }
         if(i>7)
         {
                  cout<<"  ERROR\n";   continue;
         }
         for( m=0; m < 7-i; m++)
               cout<<" ";
         for( j=i-1; j >=0;j-- )
               cout << str[j] ;
         cout << endl;
     }
     return 0;
}
