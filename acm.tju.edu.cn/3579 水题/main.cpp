#include <cstdio>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (n%i == 0 && m%j == 0)
            printf("%d %d\n", i, j);
        }

}
