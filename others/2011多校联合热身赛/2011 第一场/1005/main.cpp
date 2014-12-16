#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int g[200][200];
struct pint
{
    double x, y, r;
}jeo[200];
int t, n ,que[100000], d1[200], d2[200], d3[200], vst[200];

int dist(int i, int j)
{
    double dis = sqrt((jeo[i].x - jeo[j].x) * (jeo[i].x - jeo[j].x) + (jeo[i].y - jeo[j].y) * (jeo[i].y - jeo[j].y));
    if (dis - jeo[i].r - jeo[j].r <= 0)
        return 1;
    else
        return -1;
}

void spfa(int d[], int st)
{
    memset(vst, 0, sizeof(vst));
    vst[st] = 1;
    int head = 0, tail = 0, tmp;
    d[st] = 0;
    que[tail++] = st;
    while(head < tail)
    {
        vst[que[head]] = 0;
        for(int i = 0; i < n; i++)
            if (g[que[head]][i] != -1 && (d[i] == -1 || d[que[head]] + 1 < d[i]))
            {
                d[i] = d[que[head]] + 1;
                if (!vst[i])
                {
                    vst[i] = 1;
                    que[tail++] = i;
                }
            }
        head++;
    }
}
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        memset(g, -1, sizeof(g));

        for(int i = 0; i < n; i++)
            scanf("%lf %lf %lf", &jeo[i].x, &jeo[i].y, &jeo[i].r);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if (i != j)
                    g[i][j] = dist(i, j);

        memset(d1, -1, sizeof(d1));
        memset(d2, -1, sizeof(d2));
        memset(d3, -1, sizeof(d3));

        spfa(d1, 0);
        spfa(d2, 1);
        spfa(d3, 2);

        int ans = -1;

        for(int i = 0; i < n; i++)
            if (d1[i] != -1 && d2[i] != -1 && d3[i] != -1)
            {
                int tmp = d1[i] + d2[i] + d3[i];
                if (ans == -1 || tmp < ans)
                    ans = tmp;
            }
        if (ans == -1)
            printf("-1\n");
        else
            printf("%d\n", n - ans - 1);
    }
    return 0;
}
