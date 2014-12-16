#include"stdio.h"
#include"math.h"

int main()
{
    int i, j, n;
    int num[9];
    while(scanf("%d", &num[0]) != EOF)
    {
        i = 0;
        for(n = 1; n < 9; n++)
        scanf("%d", &num[n]);
        while(!num[i] && i != 8)
        {
            i++;
        }
        if(num[i] == 0)
        {
            printf("0\n");
            continue;
        }
        else if(num[i] == 1)
        {
            if(i == 7)
            printf("x");
            else if(i == 8)
            {
                printf("1\n");
                continue;
            }
            else printf("x^%d", 8 - i);
        }
        else if(num[i] == -1)
        {
            if(i == 7)
            printf("-x");
            else if(i == 8)
            {
                printf("-1\n");
                continue;
            }
            else printf("-x^%d", 8 - i);
        }
        else
        {
            if(i == 7)
            printf("%dx", num[i]);
            else if(i == 8)
            {
                printf("%d\n", num[i]);
                continue;
            }
            else printf("%dx^%d", num[i], 8 - i);
        }
        for(j = i + 1; j < 8; j++)
        {
            if(num[j] == 0)
            continue;
            else if(num[j] < 0)
            printf(" - ");
            else if(num[j] > 0)
            printf(" + ");
            if(num[j] == 1 || num[j] == -1)
            {
                if(j == 7)printf("x");
                else printf("x^%d", 8 - j);
            }
            else
            {
                if(j == 7)
                printf("%dx",(int)fabs((double)num[j]));
                else
                printf("%dx^%d", (int)fabs((double)num[j]), 8 - j);
            }
        }
        if(num[j] == 0)
        {
            printf("\n");
            continue;
        }
        else if(num[j] > 0)
        printf(" + ");
        else if(num[j] < 0)
        printf(" - ");
        printf("%d\n", (int)fabs((double)num[j]));
    }
    return 0;
}
