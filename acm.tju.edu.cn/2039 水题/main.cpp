#include <cstdio>
double num[100000];
int main()
{
    int i, n;
    num[0] = 0.0;
    for (i = 1; i <= 100000; i++)
        num[i] = num[i - 1] + 1 / (double)(i * 2.0);
    bool flag = 1;
    while (scanf("%d", &n) != EOF)
    {
        if (flag)
        {
            printf("# Cards  Overhang\n");
            flag = 0;
        }

        printf("%5d %9.3lf\n", n, num[n]);
    }
}
