#include <iostream>
using namespace std;
int sign[31];

int t()
{
int i ;
int temp = 0;
sign[0] = 1;
sign[2] = 3;
for (i = 3; i <= 30; i++)
{
   if (i % 2 != 0)
    sign[i] = 0;
   else 
   {    
    temp += sign[i-4]; 
    sign[i] = 3*sign[i-2] + 2 * temp;
   }  
}
}
int main ()
{
int n;
t();
    while (cin >> n && n != -1)
{
   cout << sign[n]<<endl;
}
return 0;
}
