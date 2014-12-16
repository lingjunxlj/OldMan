#include <cstdio>
#include <string>
char map[30][30];
int num[30];
int main()
{
    int n;
    while (scanf("%d",&n),n)
    {
        getchar();
        memset(num,0,sizeof(num));
        int i,j;
        for (i = 0; i < n; i++)
        gets(map[i]);
        for (i = 0; i < n; i++)
        for (j = 0; j < strlen(map[i]); j++)
        {
            if (map[i][j]=='X')
            num[i]++;
        }
        int MAX=0;
        for (i = 0; i < n; i++)
        {
            if (num[i] > MAX)
            {
                MAX = num[i];
            }
        }
        int sum=0;
        for (i = 0; i < n; i++)
        {
            sum += (MAX - num[i]);
        }
        printf("%d\n",sum);
    }
}
