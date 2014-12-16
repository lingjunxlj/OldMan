#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int Count=0;
int main ()
{
    map<string,int> MAP;
    map<string,int>::iterator it;
    string a;
    while(getline(cin,a))
    {
        if(a.length()==0)
            break;
        MAP[a]++;
        Count++;
    }
    for ( it=MAP.begin() ; it != MAP.end(); it++ )
    {
        cout << (*it).first << " ";
        printf("%.4lf\n",100*(*it).second/(double)Count);
    }
    return 0;
}
