#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 60001;
struct point
{
    double x;
    double y;
}s[MAX],ch[MAX],temp;
double dist(point a)
{
     return (a.x - s[0].x) * (a.x - s[0].x) + (a.y - s[0].y) * (a.y - s[0].y);
}
double mul(point a, point b, point c)
{
    return  ((a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y));
}
int cmp(const void *a, const void *b)
{
    point p = *(point *)a;
    point q = *(point *)b;
    if(mul(p,q,s[0])>0)
    return 1;
    else if(mul(p, q, s[0]) == 0)
    {
        if(dist(p) < dist(q))
        return 1;
        else
        return -1;
    }
    else
    return -1;
}
double area(int i, int j, int k)
{
    return fabs(ch[i].x*ch[j].y + ch[j].x*ch[k].y + ch[k].x*ch[i].y - ch[j].x*ch[i].y - ch[k].x*ch[j].y - ch[i].x*ch[k].y)/2.0;
}
int main()
{
    int n, i = 0, j = 0, k = 0, sp;
    double t;
    while (scanf("%d", &n) != EOF)
    {
        if (n == -1)
        break;

        if (n < 3)
        {
            printf("0.00\n");
            continue;
        }
        memset(s, 0, sizeof(s));
        memset(ch, 0, sizeof(ch));

        for(i = 0; i < n; i++)
        {
            scanf("%lf %lf", &s[i].x, &s[i].y);
            if(s[i].y < s[0].y || (s[i].y == s[0].y && s[i].x < s[0].x))
            {
                j = i;
            }
        }
        if(j != 0)
        {
            temp = s[0];
            s[0] = s[j];
            s[j] = temp;
        }
        qsort(s + 1, n - 1, sizeof(point), cmp);

        ch[0] = s[0];
        ch[1] = s[1];
        ch[2] = s[2];
        sp = 2;
        k = 3;
        while(k < n)
        {
            t = mul(s[k], ch[sp], ch[sp-1]);
            if(t > 0)
            ch[++sp] = s[k++];
            else
            sp--;
        }
        int len = sp + 1;
        double ans = 0;
        for(i = 0; i < len; i++)
        {
            j = (i + 1) % len;
            k = (j + 1) % len;
            while( k != i && area(i, j, k) < area(i, j, (k + 1) % len) )
            {
                k = (k + 1) % len;
            }
            if(k == i)
            continue;

            int kk = (k + 1) % len;
            while(j != kk && k != i)
            {
                ans = max( ans, area(i, j, k) );
                while(k != i && area(i, j, k) < area(i, j, (k + 1) % len))
                {
                    k = (k + 1) % len;
                }
                j = (j + 1) % len;
            }
        }
        printf("%.2lf\n", ans);
    }
}
