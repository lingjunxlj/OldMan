#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    int l;
    int r;
}seg[5001];
bool cmp (node a, node b)
{
   return (a.l < b.l) && (a.r > b.r);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int m;
        scanf("%d", &m);
        int n = 0;
        while(1)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x == 0 && y == 0)
                break;

            seg[n].l = x;
            seg[n++].r = y;
        }

        sort(seg, seg + n, cmp);

        for ()
    }
}
