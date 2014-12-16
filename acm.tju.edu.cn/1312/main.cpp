# include<stdio.h>
# include<string.h>
#define m 19
int a[25][25];

int main()
{
    int n, k, t, i, j, l, x, y, key, tt;
    scanf("%d",&t);

    l=5;
    n=m;
    while(t--)
    {

        for(i = 0; i < m; i++)
            for(j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }


        tt=0;
        for(y = 0; y < n; y++)
        {
            for(x = 0; x < m; x++)
            if(a[x][y] != 0)
            {
                if(y + l - 1 < n)
                {
                    for(i = 1, key = 0; i < l; i++)
                        if(a[x][y+i]!=a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (y + l >= n || a[x][y + l] != a[x][y]) && (y - 1 < 0 || a[x][y - 1] != a[x][y]))
                    {
                        printf("%d\n%d %d\n", a[x][y], x + 1, y + 1);
                        tt = 1;
                        break;
                    }
                }
                if(y + l - 1 < n && x + l - 1 < m)
                {
                    for(i = 1, key = 0; i < l; i++)
                        if(a[x + i][y + i] != a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (y + l >= n || x + l >= m || a[x + l][y + l] != a[x][y]) && (x - 1 < 0 || y - 1 < 0 || a[x - 1][y - 1] != a[x][y]))
                    {
                        printf("%d\n%d %d\n", a[x][y], x + 1, y + 1);
                        tt = 1;
                        break;
                    }
                }
                if(x + l - 1 < m)
                {
                    for(i = 1, key = 0; i < l; i++)
                        if(a[x + i][y] != a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (x + l >= m || a[x + l][y] != a[x][y]) && (x - 1 < 0 && a[x - 1][y] != a[x][y]))
                    {
                        printf("%d\n%d %d\n", a[x][y], x + 1, y + 1);
                        tt = 1;
                        break;
                    }
                }
                if(y + l - 1 < n && x - l + 1 >= 0)
                {
                    for(i = 1, key = 0; i < l; i++)
                        if(a[x - i][y + i] != a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (y + l >= n || x - l < 0 || a[x - l][y + l] != a[x][y]) && (x + 1 >= m || y - 1 < 0 || a[x + 1][y - 1] != a[x][y]))
                    {
                        printf("%d\n%d %d\n", a[x][y], x + 1, y + 1);
                        tt = 1;
                        break;
                    }
                }

            }
            if(tt)
            break;
        }
        if(y == n)
            printf("0\n");
     }

    return 0;
}
