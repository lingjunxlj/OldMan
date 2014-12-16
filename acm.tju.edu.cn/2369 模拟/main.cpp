#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int map[1001][1001];
int main()
{
    int x, y, r, c;
    int p, q, n;
    cin>>p>>q>>n;
    memset (map, 0, sizeof(map));
    while (n--)
    {
        cin>>x>>y>>r>>c;
        for (int i = 0; i < q; i++)
            for (int j = 0; j < p; j++)
            {
                if (sqrt((i - y) * (i - y) + (j - x) * (j - x)) <= r)
                    map[i][j] = c;
            }
    }
    for (int i = 0; i < q; i++)
    {
        for (int j = 0; j < p; j++)
            cout<<map[i][j];
        cout<<endl;
    }

}
