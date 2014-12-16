#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int n;
const int inf = 1<<30;
int map[110][110];
bool near[110];
void floyd()
{
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (map[i][k] != inf && map[k][j] != inf && (map[i][k] + map[k][j] < map[i][j]))
                    map[i][j] = map[i][k] + map[k][j];
}
int main()
{
    while (scanf("%d",&n)!=EOF)
    {
        int mi,pi;
        memset(near,0,sizeof(near));
        for (int i=0; i<=11; i++)
            for (int j=0; j<=11; j++)
            {
                map[i][j]=inf;
                map[i][i]=0;

            }
        for (int i=0; i<n; i++)
        {
            scanf("%d%d", &mi, &pi);
            for (int j=1; j<=mi; j++)
            {
                int smi,lmi;
                scanf("%d%d",&smi,&lmi);
                map[i][smi]=lmi;
            }
            if (pi==1)
                near[i]=true;
        }
        floyd();
        int MIN = inf;
        for (int i=0; i<n; i++)
        {
            if (near[i])
            {
                if (map[0][i]<MIN)
                    MIN=map[0][i];
            }
        }
        printf("%d\n",MIN);
    }
}
