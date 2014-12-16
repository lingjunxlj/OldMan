#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int num[3005];
int n;
int Max;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    while(scanf("%d",&n) != EOF)
    {
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
        }
        Max = 0;
        sort(num, num + n, cmp);
        int k = 1;
        for(int i = 1; i < n; i++)
        {
            if(num[i] == num[i - 1])
            {
                ++k;
            }
            else
            {
                if(Max < k)
                {
                    Max = k;
                }
                k = 1;
            }
        }
        if(Max < k)
        {
            Max = k;
        }
        if(n == 1)
        {
            Max = 1;
        }
        printf("%d\n",Max);
    }
}

