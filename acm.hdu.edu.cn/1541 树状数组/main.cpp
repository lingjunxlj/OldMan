#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lowbit(x)  ( (x)&(-(x)) )
int Count[32011], res[32011], n;
void update( int x, int value )
{
    while( x <= 32010 )
    {
        Count[x] += value;
        x += lowbit(x);
    }
}
int  getsum( int x )
{
    int sum = 0;
    while( x )
    {
        sum += Count[x];
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        memset(Count, 0, sizeof(Count));
        memset(res, 0, sizeof(res));
        int t = n;
        while(t--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            res[getsum(++x)]++;
            update(x, 1);
        }
        for (int i = 0; i < n; i++)
            printf("%d\n", res[i]);
    }
}
