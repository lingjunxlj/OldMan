#include <cstdio>
int num[100001];
int main()
{
    int n;
    bool mark;
    while (scanf("%d", &n), n)
    {
        mark = 1;
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);

        int t;
        for (int i = 1; i <= n; i++)
        {

            t = num[i];
            if (num[t] != i)
            {
                mark = 0;
                break;
            }
        }
        if (mark)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
    }
}
