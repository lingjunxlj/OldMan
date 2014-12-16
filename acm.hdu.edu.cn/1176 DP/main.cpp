#include <iostream>
#include <cstring>
#include <cstdio>
int a[100002][11];
int max(int x, int y)
{
    return x>y?x:y;
}
int main ()
{
    int n, x, t, Max,i,j;
    while (scanf("%d", &n), n)
    {
        memset(a,0,sizeof(a));
        Max = 0;
        while (n--)
        {
            scanf("%d %d", &x, &t);
            a[t][x]++;
            if (t>Max)
                Max=t;
        }
        for (i = Max; i >= 0; i--)
        {
            a[i][0] += max(a[i+1][0], a[i+1][1]);
            for (j = 1; j < 10; j++)
                a[i][j] += max(max(a[i+1][j-1], a[i+1][j]), a[i+1][j+1]);
            a[i][10] += max(a[i+1][9], a[i+1][10]);
        }
        printf ("%d\n",a[0][5]);
    }
    return 0;
}
