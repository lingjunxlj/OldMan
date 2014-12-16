#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 100000;
int nearvex[MAX],nearvex[MAX], lowcost[MAX], path[MAX];
int table[MAX][MAX];
int Dijkstra(int st,int end) // Dijkstra单源最短路径的算法
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
                int min = maxint;
                int pmin;
                for(j=1;j<=n;j++)
                        if(nearvex[j] != -1 && lowcost[j] < min)
                        {
                                min = lowcost[j];
                                pmin = j;
                        }
                path[nearvex[pmin]] = pmin;
                nearvex[pmin] = -1;
                if(pmin == end)
                return lowcost[end];

                for(j=1;j<=n;j++)
              if(nearvex[j] != -1 && lowcost[pmin] + table[j][pmin] < lowcost[j])
                        {
                                lowcost[j] = lowcost[pmin] + table[j][pmin];
                                nearvex[j] = pmin;
                        }
        }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
