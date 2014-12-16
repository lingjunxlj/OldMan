#include<stdio.h>

struct info{
    int d, p;
}a[10001];

void _sort(unsigned int l, unsigned int r)
{
    unsigned int i, j, x;
    struct info y;

    i = l;
    j = r;
    x = a[(l + r) / 2].p;

    do{
        while(a[i].p < x) i++;
        while(x < a[j].p) j--;

        if(!(i > j))
        {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }while(!(i > j));

    if(l < j)
        _sort(l, j);
    if(i < r)
        _sort(i, r);
}

int main()
{
    unsigned int n, i;
    long m;
    unsigned long rst;

    while(scanf("%u%u", &n, &m))
    {
        if(n == 0 && m == 0)
            break;

        for(i = 1; i <= n; i++)
            scanf("%d%d", &a[i].d, &a[i].p);
        _sort(1, n);

        for(i = n, rst = 0; i >= 1; i--)
        {
            if(m == 0)
                rst += a[i].d * a[i].p;
            else
                if(m - a[i].d >= 0)
                {
                    m -= a[i].d;
                    a[i].d = 0;
                }
                else
                {
                    a[i].d -= m;
                    m = 0;
                    rst += a[i].d * a[i].p;
                }
        }
        printf("%u\n", rst);
    }

}
