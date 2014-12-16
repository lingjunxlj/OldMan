#include <stdio.h>
#include <string.h>
#include <iostream>
#define LMax 210010
using namespace std;
char a[LMax], b[LMax], tmp[LMax], temp[LMax];
int extende[LMax], nexte[LMax], extendw[LMax], nextw[LMax];
int Max;

inline void COMPUTE_PREFIX_FUNC(char *t, int *next) {
int i = 0, Max = 0, len, j, l;
int n = strlen(t);
while( t[i] == t[i + 1] ) ++i;
next[1] = i; Max = 1;
for(i = 2; i < n; ++i) {
   len = Max + next[Max] - 1;
   l = next[i - Max];
   if(l < len - i + 1) {
    next[i] = l;
   } else {
    j = len - i + 1;
    if(j < 0) j = 0;
    while(t[i + j] == t[j] && i + j < n) ++j;
    next[i] = j;
    Max = i;
   }
}
}

inline void extend_kmp(char *s, char *t, int *extend, int *next, int n)
{
    int i = 0, Max = 0, len, j, l;
    int m = strlen(t);
    COMPUTE_PREFIX_FUNC(t, next);
    while(t[i] == s[i])
        ++i;
    extend[0] = i;
    Max = 0;
    for(i = 1; i < n; ++i)
    {
        len = Max + extend[Max] - 1;
        l = next[i - Max];
        if(l < len - i + 1)
        {
            extend[i] = l;
        }
        else
        {
            j = len - i + 1;
            if(j < 0)
                j = 0;
            while(s[i + j] == t[j] && j < m && i + j < n)
                ++j;
            extend[i] = j;
            Max = i;
        }
    }
}

inline void rev(char *s, int len) {
int i;
for(i = 0; i < len; ++i) {
   tmp[i] = s[len - 1 - i];
}
for(i = 0; i < len; ++i) {
   s[i] = tmp[i];
}
}

inline void solve(char *s, int len)
{
    int i, mid = len / 2;
    if(len <= Max)
        return;
    if(len < 2)
        return;

    for(i = mid; i < len; ++i)
        b[i - mid] = s[i];
    b[len - mid] = '\0';
    rev(s, len);
    extend_kmp(s, b, extende, nexte, len);
    rev(s, len);

    for(i = 0; i < mid; ++i) b[i] = s[mid - i - 1];
    b[i] = '\0';
    extend_kmp(s, b, extendw, nextw, len);

    extende[len] = 0;
    extendw[len] = 0;

    for(i = 0; i < mid; ++i) {
       int x = mid - i;
       if(extendw[i] >= x / 2) {
        int y = x + extende[len - i] * 2;
        if(y > Max) Max = y;
       }
    }
    for(i = mid; i < len; ++i) {
       int x = i - mid;
       if(extende[len - i] >= x / 2) {
        int y = x + extendw[i] * 2;
        if(y > Max) Max = y;
       }
    }
    solve(s, mid);
    solve(s + mid, len - mid);
}
int main()
{
    //freopen("a.txt","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int Case;
        scanf("%s",temp);
        scanf("%d", &Case);
        while(Case--)
        {
            Max = 1;
            int l, r;
            scanf("%d %d", &l, &r);
            //ans = 1;
            int x = 0;
            //for (int i = 0; i < strlen(a); i++)
                //a[i] = '.';
            for (int i = l - 1; i < r; i++)
                a[x++] = temp[i];
            //printf("%s\n", a);
            solve(a,r-l+1);
            printf("%d\n",Max);
        }

    }
}
