#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 201;
const double eps = 1e-6;
double x[MAXN], y[MAXN],n[MAXN / 2][4];
int N, xy[MAXN][MAXN];
int main()
{
    int test = 0;
    while(scanf("%d", &N) && N)
    {
        int i, k = 0;
        for(i = 0; i < N; i ++)
        {
            scanf("%lf%lf%lf%lf", &n[i][0], &n[i][1], &n[i][2], &n[i][3]);
            x[k] = n[i][0];
            y[k] = n[i][1];
            k ++;
            x[k] = n[i][2];
            y[k] = n[i][3];
            k ++;
        }
        sort(x, x + 2 * N);
        sort(y, y + 2 * N);
        memset(xy, 0, sizeof(xy));
        int i1, i2, j1, j2;
        for(i = 0; i < N; i ++)
        {
            k = 0;
            while(fabs(x[k] - n[i][0]) > eps && k < 2 * N)
            k ++;
            i1 = k;
            k = 0;

            while(fabs(y[k] - n[i][1]) > eps && k < 2 * N)
            k ++;
            j1 = k;
            k = 0;

            while(fabs(x[k] - n[i][2]) > eps && k < 2 * N)
            k ++;
            i2 = k;
            k = 0;

            while(fabs(y[k] - n[i][3]) > eps && k < 2 * N)
            k ++;
            j2 = k;
            k = 0;

            for(int I = i1; I < i2; I ++)
                 for(int J = j1; J < j2; J ++)
                      xy[I][J] = 1;
        }
        double sum = 0;
        for(int i = 0; i < 2 * N; i ++)
        {
            for(int j = 0; j < 2 * N; j ++)
            {
                 sum += xy[i][j] * (x[i + 1] - x[i]) * (y[j+1] - y[j]);
            }
        }
        printf("Test case #%d\n", ++ test);
        printf("Total explored area: %.2lf\n\n",sum);
    }
}
