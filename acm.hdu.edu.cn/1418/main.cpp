#include<iostream>
using namespace std;
int main()
{
    unsigned int n, m;
    while(1)
    {
        cin>>n>>m;
        if(n == 0 &&m == 0)
            break;
        else
            cout<<n + m - 2<<endl;
    }
    return 0;
}
