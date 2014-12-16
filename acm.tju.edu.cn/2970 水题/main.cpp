#include <cstdio>
#include <cstring>
char num[1201];
int main()
{
    //for (int i = 6; i < 1232; i += 4)
    //printf(" %d ",i);
    int n;
    while (scanf("%s", num) != EOF)
    {
        int sum;
        sum = (int)(num[strlen(num) - 1] - '0')+ 10 * (int)(num[strlen(num) - 2] - '0');
        if ((sum - 2) % 4 == 0)
        printf("\"Possible.\"\n");
        else
        printf("\"Not possible.\"\n");
    }

}
