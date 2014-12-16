#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[300][300];
int main()
{
    int t;
    cin>>t;
    int x = 1;
    while(t--)
    {
        int n;
        cin>>n;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (j == n)
                    map[i][j] = n * (n - 1) + i;
                else
                    map[i][j] = (i - 1) * (n - 1) + j;
            }
        printf("Case #%d:\n",x++);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j == 1)
                    printf("%d", map[i][j]);
                else
                    printf(" %d", map[i][j]);
            }
            printf("\n");
        }


    }
}
