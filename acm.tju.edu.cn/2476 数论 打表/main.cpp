#include <cstdio>
#include <cstring>
#define MAX 1000001
#define max 250001

int a[max],b[max];

void creat()
{
    int i, j;
    memset(a, 0, sizeof(a));
    a[0] = 2;
    for(i = 1; i < max; i++)
    {
        for(j = 1; j <= i; j++)
        {
            if( (4 * i + 1) * (4 * j + 1) > MAX)
                break;
            if(a[i] == 0 && a[j] == 0)
                a[i + j + 4 * i * j] = 1;
            else
                a[i + j + 4 * i * j] = 2;
        }
    }
    return ;
}

int main()
{
    //freopen("a.txt", "w", stdout);
    creat();
    int i, n;
    b[0] = 0;
    for(i = 1; i < max; i++)
    {
        if(a[i] == 1)
        b[i] = b[i-1] + 1;
        else
        b[i] = b[i - 1];
    }
    //for(i = 1; i < max; i++)
        //printf("%d,",b[i]);

    while(scanf("%d", &n), n)
        printf("%d %d\n", n, b[n/4]);
    return 0;
}
