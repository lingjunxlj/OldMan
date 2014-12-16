#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, sum = 3, tp;
        cin>>n;
        while(n--)
        {
            sum = (sum - 1) * 2;
        }
        cout<<sum<<endl;
    }
}
