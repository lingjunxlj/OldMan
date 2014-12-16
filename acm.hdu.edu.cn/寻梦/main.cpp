#include <stdio.h>
#include <string.h>
#define N 51
int main()
{
    int cas, i, len;
    char str[N], buf[N];

    scanf("%d", &cas);
    while ( cas-- )
    {
        scanf("%s%s", str, buf);
        len = strlen( str );
        for (i = 0; i < len / 2; i++)
            putchar(str[i]);
        printf("%s", buf);
        for (i = len/2; i < len ; i++)
             putchar(str[i]);
        putchar('\n');
    }
}
