#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 300
using namespace std;
int n, t;
int next[MAXN][MAXN];

void add(int x, int y)
{
    int k, l;
    next[x][y] = 1;


    for (k = 0; k < n; k++)
        if (next[k][x])
            next[k][y] = 1;


    for (k = 0; k < n; k++)
        if (next[y][k])
        {
            next[x][k] = 1;

            for (l = 0; l < n; l++)
                if (next[l][y])
                    next[l][k] = 1;
        }
}

int main()
{
    int i, j, k, x, y, tt = 0, ans;
    while (scanf ("%d %d", &n, &t))
    {
        if (n == 0 && t == 0)
            break;

        memset(next, 0, sizeof(next));
        ans = 0;

        for (i = 0; i < t; i++)
        {

            scanf ("%d %d", &x, &y);
            x--;
            y--;

            if (x == y)
                ans++;
            else if (next[y][x])
                ans++;
            else if (next[x][y] == 0)
                add(x, y);

        }

        printf ("%d. %d\n", ++tt, ans);
    }
}
