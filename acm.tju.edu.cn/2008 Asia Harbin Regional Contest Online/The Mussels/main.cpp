#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int cap[100000], rank[100000],capfull[100000];
int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        memset (cap, 0, sizeof(cap));
        memset (capfull, 0, sizeof(capfull));
        memset (rank, 0, sizeof(rank));

        for (int i = 1; i <= n; ++i)
            scanf("%d", &cap[i]);
        int sum = 0;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d", &rank[i]);
            if (capfull[rank[i]] < cap[rank[i]])
            {
                capfull[rank[i]]++;
                sum++;
            }
            else
            {
                int k = rank[i];
                while (k>=1)
                {
                    if (capfull[k] < cap[k])
                    {
                        capfull[k]++;
                        sum++;
                        break;
                    }
                    k--;
                }
            }
        }
        printf("%d\n", sum);

    }
}
