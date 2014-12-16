#include <iostream>
#include <cstdio>
using namespace std;
long long a(long long x)
{

    if (x == 0)
        return 0;
    if (x % 2 == 0)
        return a(x/2) + x;
    if (x % 2 == 1)
        return 3 * x - a((x - 1)/2);
}
int main()
{
    long long n;
    cin>>n;
    while (n--)
    {
        long long l;
        cin>>l;
        cout<<a(l)<<endl;
    }

}
