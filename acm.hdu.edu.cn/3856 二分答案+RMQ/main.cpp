#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#define N 400050
#define L 23
using namespace std;
int p[N], n;
char temp[N];
void Palindrome(char s[])
{
    int ans = 0, mx = 0, id = 0;
    n = strlen(s);
    temp[0] = '$';
    temp[1] = '#';
    for (int i = 0; i < n; ++i)
    {
        temp[i * 2 + 2] = s[i];
        temp[i * 2 + 3] = '#';

    }
    n = n * 2 + 2;
    temp[n] = 0;
    for(int i = 0; i < n; i++)
    {
        if(mx > i)
            p[i] = min(p[2 * id - i], p[id] + id - i);
        else
            p[i] = 1;

        for(; temp[i + p[i]] == temp[i - p[i]]; p[i]++);
            if( p[i] + i > mx )
            {
                mx = p[i] + i;
                id = i;
            }
    }
    for (int i = 0; i < n; ++i)
        p[i] = p[i + 1] - 1;
    n -= 2;
}
int st[2][N / 2][L], p2[L];
void Format_ST()
{
    p2[0] = 1;
    for (int i = 1; i < L; ++i)
        p2[i] = p2[i - 1] * 2;
    for (int i = 1; i <= n; ++i)
    {
        if (i & 1)
            st[0][(i - 1) >> 1][0] = p[i] / 2;
        else
            st[1][(i - 1) >> 1][0] = p[i] / 2;
    }
    n = n / 2;
    for (int j = 1, p = 1; j < L; ++j, p *= 2)
        for (int i = 0; i + p * 2 - 1 < n; ++i)
            for (int k = 0; k <= 1; ++k)
                st[k][i][j] = max(st[k][i][j - 1], st[k][i + p][j - 1]);
}
int RMQ(int x, int y, int t)
{
    if (x > y)
        return -1;
    int l = (int)(log((double)(y - x + 1)) / log(2.0) + 1e-6);
    return max(st[t][x][l], st[t][y - p2[l] + 1][l]);
}
char str[N / 2];
int ans(int l, int r, int t)
{
    int x = 0, y = ((r - l + t) >> 1) + 1;
    while(x + 1 < y)
    {
        int mid = (x + y) >> 1;
        if(RMQ(l + mid - t, r - mid, t) >= mid)
            x = mid;
        else
            y = mid;
    }
    return x;
}
int main()
{
    int T, q, x, y;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", str);
        Palindrome(str);
        Format_ST();
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &x, &y);
            x--;
            y--;
            printf("%d\n", max(ans(x, y, 0) * 2 + 1, ans(x, y, 1) * 2));
        }
    }
    return 0;
}
