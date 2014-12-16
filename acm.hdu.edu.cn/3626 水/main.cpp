#include <iostream>
#include <cstdio>
using namespace std;
struct ele
{
    int r;
    int c;
}point[1010];
bool cmp(ele a, ele b)
{
    if(a.r < b.r && a.c < b.c)
        return true;
    else
        return false;
}
int main()
{
    int i, j;
    int x, y;
    int ans = 1;
    int n;
    while(scanf("%d", &n), n)
    {
        for(i = 0; i < n; i++)
            scanf("%d%d", &point[i].r, &point[i].c);

        if(ans == 1)
             printf("Case %d:\n", ans++);
        else
             printf("\nCase %d:\n", ans++);
        for(i = 0; i < n; i++)
        {
            x = -1;
            y = -1;
            for(j = 0; j < n; j++)
            {
                if(cmp(point[i], point[j]))
                {
                    if(x == -1 && y == -1)
                    {
                        x = point[j].r ;
                        y = point[j].c ;
                    }
                    else
                    {
                        if(point[j].r < x)
                        {
                            x = point[j].r ;
                            y = point[j].c ;
                        }
                        else if(point[j].r == x)
                        {
                            if(point[j].c < y)
                            {
                                x = point[j].r ;
                                y = point[j].c ;
                            }
                        }
                    }
                }
            }
            printf("%d %d\n", x, y);
        }
    }
}
