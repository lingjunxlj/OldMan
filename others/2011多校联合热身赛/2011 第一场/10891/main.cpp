#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int num[10015];
int hash[20015];
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        //for (int i = 0; i <= 2*n; i++)
            //hash[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num[i]);
            hash[num[i]] = i;
        }
        bool fg = 0;
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                //int temp = num[i] - num[j];
                if (hash[2*num[j] - num[i]] > j  && hash[2*num[j] - num[i]] <= n && 2*num[j] - num[i] <= n && hash[2*num[j] - num[i]] >= 0 && 2*num[j] - num[i] >= 0)
                {
                    //printf("hash %d\n", hash[num[j]-temp]);
                    printf("Y\n");
                    fg = 1;
                    break;

                }
            }
            if(fg)
                break;
        }

        if(!fg)
            printf("N\n");
    }
}
