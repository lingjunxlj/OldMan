#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t;
struct node
{
    int d;
    int t;
}q[100011];
int flag[100011];
bool cmp(node a, node b)
{
    return a.t > b.t;
}
int main()
{
    int x = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d %d", &q[i].d, &q[i].t);
        int sum1 = 0, sum2 = 0;
        int Max = 0;
        memset(flag, 0, sizeof(flag));
        sort(q, q + n, cmp);
        Max = q[0].t + q[0].d;
        sum1 = q[0].t;
        //printf("sum1 = %d\n", sum1);
        for (int i = 1; i < n; i++)
        {
            sum2 = 0;
            if (!f
                lag[i])
            {
                for (int j = i; j < n; j++)
                {
                    sum2 += q[j].t + q[j].d;
                    if (sum2 <= sum1)
                    {
                        flag[j] = 1;
                    }
                    else
                    {
                        int temp = sum2 - q[j].t - q[j].d;
                        if (sum1 - temp >= q[j].d)
                        {
                            sum1 = q[j].t + q[j].d - (sum1 - temp);
                            Max += sum1;
                        }
                        else
                        {
                            Max += q[j].t + q[j].d - (sum1 - temp);
                            sum1 = q[j].t;
                        }
                        break;

                    }
                }
            }
        }
        printf("Case %d: %d\n", x++, Max);
    }
}
