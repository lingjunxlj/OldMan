#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn =  1001;
long long l[maxn], r[maxn], a[maxn][maxn];
int main()
{
    int n, m;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        char temp[2];
        scanf("%d %d", &n, &m);
        memset(a, 0, sizeof(a));
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%s", temp);
                if (temp[0] == 'F')
                    a[i][j] = a[i - 1][j] + 1;
                else
                    a[i][j] = 0;
                l[j] = r[j] = j;
            }
            a[i][0] = a[i][m + 1] = -1;
            for (int j = 1; j <= m; j++)
                while(a[i][l[j] - 1] >= a[i][j])
                    l[j] = l[l[j] - 1];
            for(int j = m; j >= 1; j--)
                while(a[i][r[j] + 1] >= a[i][j])
                    r[j] = r[r[j] + 1];

            for (int j = 1; j <= n; j++)
                if (ans < a[i][j]*(r[j] - l[j] + 1))
                    ans = a[i][j]*(r[j] - l[j] + 1);
        }

        printf("%I64d\n", 3*ans);
    }
}
