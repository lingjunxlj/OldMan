#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m, n;
        cin>>m>>n;
        if (m % 2 == 0 && m >= 2 * n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
