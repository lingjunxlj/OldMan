#include <iostream>
using namespace std;
char a[21];
int len;
bool vowel(char a)
{
if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
     return 1;
return 0;
}
bool r1()
{
for(int i=0; i<len; i++)
   if(vowel(a[i])) return 1;
return 0;
}
bool r2()
{
if(len < 3) return 1;
for(int i=0; i<len-2; i++)
   if(((vowel(a[i]) && vowel(a[i+1]) && vowel(a[i+2])) ||(!vowel(a[i]) && !vowel(a[i+1]) && !vowel(a[i+2]))))
      return 0;
return 1;
}
bool r3()
{
if(len == 1) return 1;
for(int i=0; i<len-1; i++)
     if(a[i]==a[i+1] && a[i]!='e' && a[i]!='o')
         return 0;
return 1;
}

int main()
{ 
while(cin >> a){
   len = strlen(a);
   if(a[0] == 'e' && a[1] == 'n' && a[2] == 'd' && len == 3) break;
   cout << '<' << a << "> is ";
   if (!(r1() && r2() && r3())) cout << "not ";
   cout << "acceptable.\n";
}
}

