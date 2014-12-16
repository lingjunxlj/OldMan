#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std;

int main()
{
    int t, x = 1;
    cin>>t;
    while(t--)
    {
        int k, m;
        cin>>k>>m;
        double ans = 1/((double)k*m*(1.0) + m + 1);
        printf("Case #%d: %.8lf\n", x++, ans);
    }
}
