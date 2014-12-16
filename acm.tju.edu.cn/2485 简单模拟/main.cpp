#include <cstdio>
#include <string>
const int MAX = 20;
int num[MAX][MAX];
bool flag[MAX];
int main()
{
    num[1][0] = 1;
    num[2][0] = 2;
    num[2][1] = 1;
    int i, j , k, temp;
    for (i = 3; i <= 13; i++)
    {
        memset(flag, 0, sizeof (flag));
        temp = -1;
        for (j = 2; j <= i+1 ; j++)
        {
            for (k = 1; k <= j;)
            {
                temp = (temp + 1) % i;
                if (!flag[temp])
                k++;
            }
            flag[temp] = 1;
            num[i][temp] = j - 1;
        }
    }
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int temp1;
        scanf("%d", &temp1);
        printf("%d", num[temp1][0]);

        for(i = 1; i < temp1; i++)
        printf(" %d",num[temp1][i]);

        printf("\n");
    }
}


