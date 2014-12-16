#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#define N 210
#define Max 0x7fffffff
using namespace std;
struct Node
{
    int x;
    int y;
}node[N];
double Map[N][N];
int n;
double dis(Node a,Node b)
{
    return sqrt((double)(a.x - b.x) * (a.x-b.x) + (double)(a.y - b.y) * (a.y-b.y));
}

void prime()
{
    int i,j,k;
    double sum;
    double temp[N];
    int flag[N];
    for (i = 0; i < n; i++)
    {
        temp[i] = Map[0][i];
        flag[i] = 0;
    }
    flag[0] = 1;
    sum = 0;
    for (i = 0; i < n - 1; i++)
    {
        double m = Max;
        for (k = -1, j = 0; j < n; j++)
        {
            if(flag[j] == 0 &&m > temp[j])
            {
                k = j;
                m = temp[j];
            }
        }
        if(k==-1)
            break;
        flag[k] = 1;
        sum += m;

        for (j=0;j<n;j++)
        {
            if(flag[j]==0&&temp[j]>Map[k][j])
                temp[j] = Map[k][j];
        }
    }

    if(k==-1)
        printf("oh!\n");
    else
        printf("%0.1lf\n",sum*100);
}
int main()
{
    int i, j, k;
    int Case;
    scanf("%d", &Case);
    while (Case--)
    {
        scanf("%d", &n);
        for (i=0;i<n;i++)
            scanf("%d %d",&node[i].x,&node[i].y);

        for (i = 0; i < n; i++)
        {
            Map[N][N] = Max;
            for (j = i + 1; j < n; j++)
            {
                Map[i][j] = dis(node[i], node[j]);
                if(Map[i][j] >= 10 && Map[i][j] <= 1000)
                    Map[j][i] = Map[i][j];
                else
                    Map[i][j] = Map[j][i] = Max;
            }
        }
        prime();
    }
}
