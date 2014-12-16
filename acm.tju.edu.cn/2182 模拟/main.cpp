#include <cstdio>
#include <cstring>
bool mark[50][50];
int num[2501];
int main()
{
    int n;
    bool fg;
    while (scanf("%d", &n) != EOF)
    {
        int n1;
        scanf("%d", &n1);
        fg = 1;

        if (n1 != n*(n - 1)/2)
            fg = 0;

        for (int i = 0; i < n1; i++)
            scanf("%d", &num[i]);
        memset (mark, 0, sizeof(mark));
        for (int i = 0; i < n1 - 1; i++)
            mark[num[i]][num[i + 1]] = mark[num[i + 1]][num[i]] = 1;
        mark[num[0]][num[n1 - 1]] = mark[num[n1 - 1]][num[0]] = 1;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (mark[i][j] == 0 && i != j ){
                    fg = 0;
                    break;
                }

        if (fg)
            printf("Accepted\n");
        else
            printf("Wrong Answer\n");
    }
}
