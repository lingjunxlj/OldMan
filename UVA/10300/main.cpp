#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int sum = 0;
        int a, b, c;
        cin>>n;
        while(n--)
        {
            cin>>a>>b>>c;
            sum += (a*c);
        }
        cout<<sum<<endl;
    }
}
