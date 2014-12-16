#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
#define N 1008
int dist[N];
int g[N][N];
void Djstra(int s, int n)
{
    int flag[N];
    int i, j, min, u;

    for(i = 1; i < n; i++)
    {
        dist[i] = g[s][i];
        flag[i] = 1;
    }
    flag[s] = 0 ;
    for(i = 2; i < n; i++)
    {
        min = 0x7fffff;
        for(j = 1; j < n; j++)
        {
            if(flag[j] && (dist[j] < min))
            {
                u = j;
                min = dist[j];
            }
        }
        flag[u] = 0 ;
        for(j = 2; j < n; j++)
            if( flag[j] && (dist[u] + g[u][j] < dist[j]) )
                dist[j] = dist[u] + g[u][j];
    }
}

int main()
{
    int i, j, k, n, t, flag, a, b;
    char start[50], end[50];
    map<string, int>M;
    while(scanf("%d",&n) && n != -1)
    {
        M.clear();
        flag = 0;
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                g[i][j] = 0x7fff;

        scanf("%s %s", start, end);
        M[start] = 1;
        M[end] = 2;
        if(strcmp(start, end) == 0)
        flag =1;
        k = 3;
        for(i = 0; i < n; i++)
        {
            scanf("%s %s %d", start, end, &t);
            a = M[start];
            b = M[end];
            if(a == 0)
                a=M[start]=k++;
            if(b == 0)
                b=M[end]=k++;
            if(t < g[a][b])
            g[a][b] = g[b][a] = t;
        }
        if(flag)
        {
            printf("0\n");
            continue;
        }
        Djstra(1,k);
        printf("%d\n",dist[2]<0x7fff?dist[2]:-1);
    }

    return 0;
}
