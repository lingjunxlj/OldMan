#include <iostream>
#include <math.h>
using namespace std;
const int MAXX = 101;
const int inf = 999999;
double sum = 0;
struct node
{
    double x;
    double y;
}point[MAXX];
double map[MAXX][MAXX];
double lowcost[MAXX];
void Init(int n)
{
    int i;
    int j;
    for (i = 0; i < n; ++i)
    {
        cin >> point[i].x >> point[i].y;
        for (j = 0; j < n; j++)
        {
            map[i][j] = inf;
        }
    }
    for (i = 0; i < n; ++i)
    {
        for (j = 0 ; j < n; ++j)
        {
        map[i][j] = sqrt((point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y));
        }
    }
}
void primer(double map[MAXX][MAXX], int n)
{
    int i = 0;
    int j = 0;
    for (i = 1; i < n; ++i)
    {
        lowcost[i] = map[0][i];
    }
    lowcost[0] = 0;
    for (i = 1; i < n; ++i)
    {
        int dex = 0;
        double min = inf;
        for (j = 1; j < n; ++j)
        {
            if (min > lowcost[j] && lowcost[j])
            {
                min = lowcost[j];
                dex = j;
            }
        }
        sum+=lowcost[dex];
        lowcost[dex]=0;
        for (j = 1; j < n; ++j)
        {
            if (map[dex][j] < lowcost[j] && lowcost[j])
            {
                lowcost[j] = map[dex][j];
            }
        }
    }
}

int main()
{
    int n; 
    cin >> n;
    Init(n);
    primer(map,n);
    printf("%.2lf\n",sum);
}
