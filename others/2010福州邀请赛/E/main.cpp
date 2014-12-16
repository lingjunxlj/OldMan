#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s1[111], s[111];
int main()
{
    int t, x = 0;
    cin>>t;
    while(t--)
    {
        int len;
        x++;
        cin>>len>>s;
        strcpy(s1,s);
        sort(s, s + len);
        int ans = 0;
        for (int i = 0; i < len; i++)
        {
            if (s1[i] != s[i])
                ans++;
        }
        printf("Case %d: %d\n", x, ans);

    }
}
