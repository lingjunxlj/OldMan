#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define lowbit(x)  ( (x)&(-(x)) )
struct node
{
    int num;
    int pos;
}queue[500001];
bool cmp(node x, node y)
{
    return x.num < y.num;
}
int n, p[500001], Count[500001];
void update( int x, int value )
{
    while( x <= n )
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
    while(scanf("%d", &n), n)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &queue[i].num);
            queue[i].pos = i;
        }

        sort(queue + 1, queue + n + 1, cmp);

        __int64 ans= 0;
        memset(Count, 0, sizeof(Count));
        int id = 1;
        p[queue[1].pos] = 1;

        for (int i = 2; i <= n; i++)
        {
            if (queue[i].num == queue[i - 1].num)
                p[queue[i].pos] = id;
            else
                p[queue[i].pos] = ++id;
        }
        for( int i = 1; i <= n; ++i )
        {
            update( p[i], 1 );
            ans += (__int64)( i - getsum( p[i] ));
        }
        printf("%I64d\n", ans );

    }
}

