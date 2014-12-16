#include <cstdio>
#define MAXN 34003

int main()
{
    int i, j, k;
    char a[MAXN];

    for (i = 2; i < MAXN; ++i)
        a[i] = 1;

    for (i = 2; i < MAXN; ++i)
    {
        if (!a[i])
            continue;

        k = 0;
        for (j = i + 1; j < MAXN; ++j)
        {
            if (a[j])
            {
                if ((++k) == i)
                {
                    a[j] = 0;
                    k = 0;
                }
            }
        }
    }

    while (1)
    {
        scanf("%d", &k);

        if (0 == k)
            break;
        i = 0;

        while (k)
        {
            if (a[i + 2])
                --k;
            ++i;
        }
        printf("%d\n", i + 1);
    }
}
