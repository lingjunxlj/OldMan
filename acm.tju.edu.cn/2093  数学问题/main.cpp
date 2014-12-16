#include<stdio.h>
int main()
{
    int n, l, a, b, f, L;
    double time, p, ans, min;
    scanf("%d %lf", &n, &time);
    f = n / 2;
    p = time / (f - 0.5);
    printf("N =%4d, T =%6.1lf\n", n, time);
    while(scanf("%d %d", &a, &b) != EOF)
    {
        l = a - b;
        L = a - b;
        if(l < 0)
        {
            l =- l;
            L += n;
        }
        ans = (l - 0.5) * p;

        if((ans/2) > (time-ans/2))
        min = (time - ans / 2);
        else
        min = (ans / 2);

        printf("Chair%4d meets chair%4d, remaining time =", a, b);

        if(L < f)
        printf("%6.1lf\n", min);
        else
        printf("%6.1lf\n", time-min);

    }
}
