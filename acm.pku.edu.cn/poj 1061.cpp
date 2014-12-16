#include <iostream>
using namespace std;
long long GCD(long long a,long long b)
{
    if (b==0)
    return a;
    return GCD(b,a%b);
}
