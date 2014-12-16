#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 5000;
int nearvex[MAX];
double table[101][101],lowcost[MAX];
int dis, n, m;
void Dijkstra(int st,int end)
{
        int i,j;
        int top = -1;
        nearvex[st] = -1;
        dis = 0;
        for(i=1;i<=n;i++)
                if( i != st )
                {
                        nearvex[i] = st;
                        lowcost[i] = table[i][st];
                }
        for(i=1;i<=n;i++)
        {
                double min = 0;
                int pmin;
                for(j=1;j<=n;j++)
                        if(nearvex[j] != -1 && lowcost[j] > min)
                        {
                                min = lowcost[j];
                                pmin = j;
                        }

                nearvex[pmin] = -1;

                if(pmin == end)
                {
                    printf("%.6lf percent\n",lowcost[pmin]*100);
                    return ;
                }


                for(j=1;j<=n;j++)
                if(nearvex[j] != -1 && lowcost[pmin] * table[j][pmin] > lowcost[j])
                        {
                                lowcost[j] = lowcost[pmin] * table[j][pmin];
                                nearvex[j] = pmin;
                        }
        }
}

int main()
{

    while (scanf("%d", &n), n)
    {
        scanf("%d", &m);
        int a, b;
        double p;
        memset(table, 0,sizeof(table));
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %lf", &a, &b, &p);
            table[a][b] = table[b][a] = p/100.0;
        }
        Dijkstra(1, n);
    }
    return 0;
}
