#include <iostream>
#include <cstdio>
using namespace std;
int num;
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        int fg = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &num);
            if (i == num)
            {
                if (!fg)
                {
                    printf("%d", num);
                    fg = 1;
                }

                else
                {
                    printf(" %d", num);

                }

            }
        }
        if (!fg)
            printf("No Mistake\n");
        else
            printf("\n");
    }
}
