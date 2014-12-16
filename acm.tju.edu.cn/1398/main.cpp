#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int mar[30], sum, m;
bool visit[30], flag;
bool cmp(int a, int b)
{
    return a > b;
}
void dfs(int k, int sun, int N)
{
    if(sun == sum)
    {
        N++;
        if(N == 3)
        {
            flag = true;
            return;
        }
        else
        {
            dfs(N, 0, N);
        }
    }
    else
    {
        for(int i = k; i < m && !flag; ++i)
        {
            if(!visit[i] && (mar[i]+sun) <= sum)
            {
                visit[i] = true;
                dfs(i+1, sun+mar[i], N);
                visit[i] = false;
            }
        }
    }
}


int main()
{
    int n, i, j;
    scanf("%d", &n);

    while (n--)
    {
        memset(visit, 0, sizeof(visit));
        sum = 0;
        flag = 0;

        scanf("%d", &m);
        for (i = 0; i < m; i++)
        {
            scanf("%d", &mar[i]);
            sum += mar[i];
        }
        sort (mar, mar+m, cmp);

        if (sum % 4  != 0 )
        printf("no\n");

        else
        {
            if (sum / 4 < mar[m-1])
            printf("no\n");

            else
            {
                dfs(0, 0, 0);

                if(flag)
                printf("yes\n");
                else

                printf("no\n");
            }
        }
    }
}






