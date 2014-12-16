#include <cstdio>
char mine[20][20], t[20][20], st[20][20];
int f[8][2] =
{
    0, 1, 1, 0, 0, -1, -1, 0,
    1, 1, 1, -1, -1, 1, -1, -1
};
int main()
{
    int i, j, k, n;
    scanf("%d", &n);
    for(i = 0; i < n; i ++)
        scanf("%s",mine[i]);
    for(i = 0; i < n; i ++)
        scanf("%s", t[i]);
    bool flag = 0;

    for(i = 0; i < n; i ++)
        for(j = 0; j < n; j ++)
            if(mine[i][j] == '*' && t[i][j] == 'x')
            {
                flag = 1;
                goto loop;
            }
    loop:;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            if(mine[i][j] == '*' && flag)
            st[i][j] = '*';

            else if(t[i][j] == 'x')
            {
                int sum = 0;
                for(k = 0; k < 8; k ++)
                {
                    int a = i + f[k][0];
                    int b = j + f[k][1];
                    if(a < 0 || a > n - 1 || b < 0 || b > n - 1)
                    continue;
                    if(mine[a][b] == '*')
                    sum++;
                }
                st[i][j] = sum + '0';
            }
            else
            st[i][j] = '.';
        }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        printf("%c", st[i][j]);

        printf("\n");
    }
    return 0;
}
