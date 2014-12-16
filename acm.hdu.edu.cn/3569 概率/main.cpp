#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int t, x = 1;
    cin>>t;
    while(t--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        int sum = 0, num;
        for (int i = 0; i < n; i++)
        {
            cin>>num;
            sum += num;
        }
        printf("Case %d: %.5lf\n", x++, (double)sum/(n/(m*1.0)));
    }

}
