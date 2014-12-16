#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int num[5];
int main()
{
    int t, x = 0;
    cin>>t;
    while(t--)
    {
        x++;
        for (int i = 0; i < 4; i++)
            cin>>num[i];
        sort(num, num + 4);
        if (num[0]+num[3] == num[1] + num[2])
            printf("Case %d: Yes\n", x);
        else
            printf("Case %d: No\n", x);
    }
}
