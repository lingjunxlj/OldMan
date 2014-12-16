#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int map[102][102], appear[102][102];
void DFS (int x, int y, int c)
{
    if(map[x + 1][y] == c && appear[x + 1][y] == 0)
    {
        appear[x + 1][y] = 1;
        DFS(x + 1, y, c);
    }
    if(map[x][y + 1] == c && appear[x][y + 1] == 0)
    {
        appear[x][y + 1] = 1;
        DFS(x, y + 1, c);
    }
    if(map[x - 1][y] == c && appear[x - 1][y] == 0)
    {
        appear[x - 1][y] = 1;
        DFS(x - 1, y, c);
    }
    if(map[x][y - 1] == c && appear[x][y - 1] == 0)
    {
        appear[x][y - 1] = 1;
        DFS(x, y-1, c);
    }
}
main()
{
    int t, time = 1, a, b, c;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, num[256];
        memset(num, 0, sizeof(num));
        memset(map, 0, sizeof(map));
        memset(appear, 0, sizeof(appear));
        char s[102];
        scanf("%d %d", &n, &m);
        for(a = 1; a <= n; a++)
        {
            scanf("%s", s);
            for(b = 1, c = 0; b <= m; b++, c++)
            {
                map[a][b] = s[c];
                appear[a][b] = 0;
            }
        }
        for(a = 1; a <= n; a++)
            for(b = 1; b <= m; b++)
                if(appear[a][b] == 0)
                {
                   DFS(a, b, map[a][b]);
                   num[map[a][b]]++;
                }
        int max = 0;

        for(a = 'a'; a <= 'z'; a++)
            if(num[a] > max)
                max = num[a];
        printf("World #%d\n", time++);

        for(a = max; a >= 1; a--)
            for(b = 'a'; b <= 'z'; b++)
                if(num[b] == a)
                    printf("%c: %d\n", b, a);
    }
    return 0;
}
