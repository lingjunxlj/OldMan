#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1000;
const int MAXM = 2001;
int main()
{
      char str[MAXM];
      int n, seq[MAXN];
      while(scanf("%d", &n) != EOF)
      {
           getchar();
           gets(str);
           seq[0] = 0;
           //以第seq[0] + 1作为第1 个任务
           for(int i = 1; i < n; i++)
           {
                 gets(str);
                 int p = -1;
                 if(str[2 * seq[0]] == '1')
                 p = 0;

                 //str[2 * seq[0]] == '1'表示第i + 1个任务能转移到第1个任务;
                 //故把第i + 1个任务插在sequence的第1个位置

                 else if(str[2 * seq[i - 1]] == '0')
                 p = i;

                 //str[2 * seq[i - 1]] == '0'表示第seq[i - 1] + 1个任务能转移到第i + 1个任务;
                 //故把第i + 1个任务插在sequence的第i + 1个位置

                 else
                        for(int j = i - 1; j >= 1 && p == -1; j--)
                                if(str[2 * seq[j - 1]] == '0' && str[2 * seq[j]] == '1')
                                        p = j;

                 //str[2 * seq[j - 1]] == '0'表示第seq[j - 1] + 1个任务能转移到第i + 1个任务;
                 //str[2 * seq[j]] == '1'表示第i + 1个任务能转移到第seq[j] + 1个任务;
                 //故把第i + 1个任务插在sequence的第j + 1个位置

                 for(int j = i; j > p; j--)
                        seq[j] = seq[j - 1];

                 seq[p] = i;

           }
           printf("1\n%d\n", n);

           for(int i = 0; i < n - 1; i++)
                 printf("%d ", seq[i] + 1);

           printf("%d\n", seq[n - 1] + 1);
      }

}
