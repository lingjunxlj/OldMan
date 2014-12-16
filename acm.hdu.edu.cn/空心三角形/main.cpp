#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[150][150];
int n;
char pic;
int main()
{
   int fg = 0;
    while(cin>>pic)
    {
        if (pic == '@')
            break;
        if (fg)
            cout<<endl;
        fg = 1;
        cin>>n;
        if (n == 0)
            continue;
        int s = n-1, t = n-1;
        memset(map, 0, sizeof(map));
        map[0][n-1] = 1;
        for (int i = 1; i < n; i++)
        {
            if (i != n - 1)
            {
                map[i][--s] = map[i][++t] = 1;
            }
            else
                for (int j = 0; j < 2*n - 1; j++)
                    map[i][j] = 1;
        }
        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n + i; j++)
                if (map[i][j])
                    cout<<pic;
                else
                    cout<<" ";
            cout<<endl;
        }
       // cout<<endl;
    }
}
