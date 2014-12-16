#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int start, end, edge, top;
int degree[2001], visit[2001], ans[2001];
int min(int x, int y)
{
    return x<y?x:y;
}
int max(int x, int y)
{
    return x>y?x:y;
}
struct node
{
    int x;
    int y;
}point[2001];
bool DR(int n)
{
    for (int i = 1; i <= n; i++)
        if(degree[i]%2 == 1)
            return false;
    return true;
}
void euler(int u)
{
    for (int i = 1; i <= edge; i++)
        if (!visit[i] && (point[i].x == u || point[i].y == u) )
            {
                visit[i] = 1;
                euler(point[i].x + point[i].y - u);
                ans[top++] = i;
            }
}
int main()
{
    int x, y, z, t = 0;
    start = end = edge = top = 0;
    while (scanf("%d %d", &x, &y) != EOF)
    {

        if (x == 0 && y == 0)
        {
            t++;
            if (t == 2)
                break;
            memset(visit, 0, sizeof(visit));
            if (!DR(end))
                printf("Round trip does not exist.\n");
            else
            {
                euler(1);
                for (int i = top - 1; i >= 1; i--)
                    printf("%d ", ans[i]);
                printf("%d\n", ans[0]);
            }
            memset(degree, 0, sizeof(degree));
            start = end = edge = top = 0;
        }
        else
        {
            scanf("%d", &z);

            point[z].x = x;
            point[z].y = y;
            edge++;
            degree[x]++;
            degree[y]++;
            end = max(end, max(x, y));
            t = 0;
        }
    }
    return 0;
}
