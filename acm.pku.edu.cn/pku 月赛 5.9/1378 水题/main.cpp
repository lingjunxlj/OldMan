#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    map<string,string> mymap;
    string a,b,d;
    while (1)
    {
        d = getchar();
        if ( d == "\n" )
        break;
        cin >> a>> b ;
        a = d + a;
        mymap[b]=a;
        getchar();
    }
    string c;
    while ( cin >> c )
    {
        if ( mymap[c] == "" )
        cout<<"eh"<<endl;
        else
        cout<<mymap[c]<<endl;
    }
}
