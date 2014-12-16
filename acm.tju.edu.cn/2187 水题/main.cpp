#include <cstdio>
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m))
    {
        if (n == 0 && m == 0 )
        break;
        printf("%.3lf\n",(double)(n-m)/(n+m));
    }


}
