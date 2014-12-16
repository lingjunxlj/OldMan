#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int num[1000];
const int Max = 100000;
int prime[Max];
bool flag[Max];
int size = 0;
inline void genPrime()
{
    memset(flag, true, sizeof(flag));
    for(int i=2; i<=Max/2; ++i)
    {
        if(flag[i])
        {
            for(int j=i<<1; j<=Max; j+=i)
                flag[j] = false;
        }
    }
}

int gcd(int n, int m)
{
    if (m == 0)
        return n;
    return gcd(m, n%m);
}
bool judge(int a, int b)
{
    if (a == 1||(flag[a]&&flag[b]) || b - a == 1 || (a&1 == 1 && b&1 == 1 && b - a == 2) || flag[b] || (flag[a]) && (b%a != 0) || (a * 2 + 1 == b) || (a * 2 - 1 == b)|| gcd(a, b) == 1)
        return 1;
    return 0;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &num[i]);
        sort(num, num + n);
        int ans = 0;
        for (int i = 0; i < n - 2; i++)
            for (int j = i + 1; j < n - 1; j++)
            {
                if(judge(num[i], num[j]))
                    for (int k = j + 1; k < n; k++)
                    {
                        if (judge(num[i], num[k]) && judge(num[j], num[k]))
                            ans++;
                    }
            }
        printf("%d\n",ans);
    }
}
