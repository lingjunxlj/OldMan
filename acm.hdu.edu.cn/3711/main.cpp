#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int f(long a, long b)
{
    int cnt = 0;
    while (a || b)
    {
        int m = a&1;
        int n = b&1;
        if(m != n)
            cnt++;
        a /= 2;
        b /= 2;
    }
    return cnt;
}
int main()
{

    int t, m, n, minn;
    long minx;
    long a[200], b[200];
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        for(int i=1; i<=m; ++i)
            cin >> a[i];
        sort(a+1, a+m+1);
        for(int i=1; i<=n; ++i)
            cin >> b[i];
        for(int i=1; i<=n; ++i)
        {
            minn = 99999;
            minx = 0;
            for(int j=1; j<=m; ++j)
                if(minn > f(a[j], b[i]))
                {
                    minn = f(a[j], b[i]);
                    minx = a[j];
                }
            cout << minx << endl;
        }
    }
}
