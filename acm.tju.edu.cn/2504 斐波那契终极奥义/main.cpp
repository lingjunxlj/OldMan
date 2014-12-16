#include <iostream>
using namespace std;
int main()
{
    int cas, n, i, j;
    int a[50];

    a[1] = 1;
    a[2] = 2;
    for (i = 3; i <= 44; i++)
        a[ i ] = a[i-2] + a[i-1];

    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);
        for (i = 44; i > 0; i--)
            if (n >= a[ i ])
            {
                for (j = i; j > 0; j--)
                {
                    if (n >= a[j])
                    {
                        printf("1");
                        n -= a[j];
                    }
                    else
                        printf("0");
                }
                printf("\n");
                break;
            }
    }
    return 0;
}
