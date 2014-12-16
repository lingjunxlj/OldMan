#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long num[500001];
bool fg[500001];
int main()
{
    int t, x = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        memset(fg, 0, sizeof(fg));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%I64d", &num[i]);

        long long temp;
        for (int i = n - 1; i >= 0; i--)
        {
            temp = num[i];

            if (temp <= 0 && !fg[i])
            {
                fg[i] = 1;
                bool ok = 0;
                for (int j = i - 1; j >= 0; j--)
                {
                    temp += num[j];
                    ok = 1;
                    if (temp <= 0)
                    {
                        fg[j] = 1;
                    }
                    else
                    {
                        ok = 0;
                        break;
                    }
                }
                if (ok)
                {
                    for (int j = n - 1; j >= i; j--)
                    {
                        temp += num[j];
                        if (temp <= 0)
                        {
                            fg[j] = 1;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!fg[i])
                ans++;
        printf("Case %d: %d\n", x++, ans);
    }
}
