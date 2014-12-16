#include <cstdio>
#include <cstring>
int a[25][25];

int main()
{
    int k, t, i, j, l, x, y, key, tt;
    scanf("%d", &t);
    while(t--)
    {

        for(i = 0; i < 19; i++)
            for(j = 0; j < 19; j++)
                scanf("%d", &a[i][j]);
        tt=0;
        for(y = 0; y < 19; y++)
        {
            for(x = 0; x < 19; x++)
            if(a[x][y] != 0)
            {
                if(y + 4 < 19)
                {
                    for(i = 1, key = 0; i < 5; i++)
                        if(a[x][y + i] != a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (y + 5 >= 19 || a[x][y + 5] != a[x][y]) && (y - 1 < 0 || a[x][y - 1] != a[x][y]))
                    {
                        printf("%d\n%d %d\n", a[x][y], x+1, y+1);
                        tt = 1;
                        break;
                    }
                }
                if(y + 4 < 19 && x + 4 < 19)
                {
                    for(i = 1, key = 0; i < 5; i++)
                        if(a[x + i][y + i] != a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (y + 5 >= 19 || x + 5 >= 19 || a[x + 5][y + 5] != a[x][y]) && (x - 1 < 0 || y - 1 < 0 || a[x - 1][y - 1] != a[x][y]))
                    {
                        printf("%d\n%d %d\n", a[x][y], x+1, y+1);
                        tt = 1;
                        break;
                    }
                }
                if(x + 4 < 19)
                {
                    for(i = 1, key = 0; i < 5; i++)
                        if(a[x + i][y] != a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (x + 5 >= 19 || a[x + l][y] != a[x][y]) && (x - 1 < 0 && a[x - 1][y] != a[x][y]))
                    {
                        printf("%d\n%d %d\n", a[x][y], x + 1, y + 1);
                        tt = 1;
                        break;
                    }
                }
                if(y + 4 < 19 && x - 4 >= 0)
                {
                    for(i = 1, key = 0; i < 5; i++)
                        if(a[x-i][y+i]!=a[x][y])
                        {
                            key = 1;
                            break;
                        }
                    if(!key && (y + 5 >= 19 || x - 5 < 0 || a[x - 5][y + 5] != a[x][y]) && (x + 1 >= 19 || y - 1 < 0|| a[x + 1][y - 1] != a[x][y]))
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
        if(y == 19)
            printf("0\n");

    }
}
