#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[1000],a[1000],ans[1000], temp[1000];
int n;
//f[i]表示以a[i]结尾的最长上升子序列的长度
//ans[i]表示以a[i]结尾的最长上升子序列的个数
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            f[i] = 1;
            temp[i] = 0;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
            {
                if(a[j] < a[i] && f[i] < f[j] + 1)
                    f[i] = f[j] + 1;
            }

        int _max = 0;
        for(int i = 0; i < n; i++)
            if(f[i] > _max)
                _max = f[i];
            a[n] = (1<<30);
            f[n] = _max+1;
        for(int i = 0; i < n; i++)
        {
            if(f[i] == 1)
                ans[i] = 1;
            else
                ans[i] = 0;
        }
        ans[n] = 0;
        for(int l = 1; l <= _max; l++)
        {
            for(int i = 0; i < n; i++)
            {
                if(f[i] == l)
                {
                    int j = i + 1;
                    while(j <= n && a[j] != a[i] && temp[i] == 0 && temp[j] == 0)//排除相等情况
                    {
                        if(a[j] > a[i] && f[j] == f[i] + 1 && temp[i] == 0 && temp[j] == 0)
                        {
                            ans[j] += ans[i];
                            temp[i] = temp[j] = 1;
                        }

                        j++;
                    }
                }
            }
        }
        int Max = 0;
        for (int i = 0; i < n; i++)
            if (f[i] == _max && ans[i] != 0)
                Max++;

        printf("%d\n%d\n", _max, Max);
    }
    return 0;
}
