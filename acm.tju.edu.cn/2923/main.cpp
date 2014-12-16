#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[101], b[101];
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        cin>>a>>b;
        int sum = (int)(a[strlen(a)-1] - '0' + b[strlen(b)-1] - '0') % 2;
        if (!sum)
        cout<<"MEET"<<endl;
        else
        cout<<"CANNOT"<<endl;
    }
}
