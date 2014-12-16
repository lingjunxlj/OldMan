#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int sum[1001], num[1001];
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            sum[i] = 0;
        }

        //sum[0] = num[0];
        for (int i = 0; i < n; i++)
        {
            int Max = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (num[i] > num[j] && Max < sum[j])
                    Max = sum[j];
            }
            sum[i] = Max + num[i];
        }
        int MAX = 0;
        for (int i = 0; i < n; i++)
            if (MAX < sum[i])
                MAX = sum[i];
        printf("%d\n", MAX);

    }
}
