#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[30][30], ans, n;
int color[30];
char str[30];
bool cmp_color(int index, int color_num)
{
    for (int i = 0; i < n; i++)
        if (map[index][i] && color[i] == color_num)
            return 0;
    return 1;
}
void DFS(int index, int color_num)
{
    if (color_num >= ans)
        return;
    if (index == n)
    {
        ans = color_num;
        //printf("ans = %d\n", ans);
        return;
    }

    for (int i = 1; i <= color_num; i++)
    {
        if (cmp_color(index, i))
        {
            color[index] = i;
            //printf("i == %d\n", i);
            DFS(index + 1, color_num);
            color[index] = 0;
        }
    }
    color_num++;
    //printf("color_num = %d\n", color_num);
    color[index] = color_num;
    DFS(index + 1, color_num);
    color[index] = 0;
}
int main()
{
    while(scanf("%d", &n), n)
    {
        memset(map, 0, sizeof(map));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            int len = strlen(str);
            int head = str[0] - 'A';
            for (int j = 2; j < len; j++)
            {
                map[head][str[j] - 'A'] = 1;
                map[str[j] - 'A'][head] = 1;
            }
        }
            /*
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                if (map[i][j])
                    printf("map[%d][%d]\n", i, j);
            */
        ans = 0x7fffff;
        DFS(0, 0);
        if (ans == 1)
            printf("%d channel needed.\n", ans);
        else
            printf("%d channels needed.\n", ans);

    }
}
