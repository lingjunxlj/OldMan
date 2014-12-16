#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[1<<15];
int main()
{
    int n, m, y;
    while(cin>>n>>m)
    {
        memset(num, 0, sizeof(num));
        while(n--)
        {
            int k;
            cin>>k;
            y = 0;
            while(k--)
            {
                int x;
                cin>>x;
                y = y | (1 << (x - 1));
            }
            num[y] = 1;
            for (int i = 0; i<= 1 << m; i++)
                if (num[i])
                    num[i | y] = 1;
        }
        int ans = 0;
        for (int i = 0; i <= 1 << m; i++)
            if (num[i])
                ans++;
        printf("%d\n", ans);
    }
}
