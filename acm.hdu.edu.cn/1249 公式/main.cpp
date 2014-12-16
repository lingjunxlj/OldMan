#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<3 * n * (n - 1) + 2<<endl;
    }
}
