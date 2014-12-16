#include <cstdio>
#include <cstring>
const int MAX = 30;
int map[MAX][MAX], sx[MAX], sy[MAX];
int dir[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},{1, -2}, {1, 2}, {2, -1}, {2, 1}};
int p, q, sign, step;
void dfs(int i, int j)
{
    if (sign) return;
    int x, y, k;
    step++;
    sx[step] = i; sy[step] = j;
    if(step == p * q){
        sign = 1;
        return;
    }
    map[i][j] = 1;
    for (k = 0; k < 8; k++)
    {
        y = j + dir[k][0]; x = i + dir[k][1];
        if (map[x][y] == 0 && x > 0 && x <= p && y > 0 && y <= q)
        {
            dfs(x, y);
            step--;
        }
    }
    map[i][j] = 0;
}

int main()
{
    int i, j, n, t = 0;
    scanf("%d", &n);
    while(n--)
    {
        sign = 0;  step = 0;  t++;
        scanf("%d%d", &p, &q);
        memset (map, 0, sizeof (map));

        dfs(1, 1);
        printf("Scenario #%d:\n", t);
        if (sign)
        {
            for (i = 1; i <= p * q; i++)
                printf("%c%d", sy[i] + 'A' - 1, sx[i]);
            printf("\n");
        }
        else
            printf("impossible\n");
        //if (n != 0)
            printf("\n");
    }
    return 0;
}
