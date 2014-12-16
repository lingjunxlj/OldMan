#include <cstdio>
#include<cmath>
int n;
bool flag;
void dfs(int a, int b, int c, int d)
{
    if(b + d > n)
    return ;
    int ac = a + c;
    int bd = b + d;
    dfs(a, b, ac, bd);
    if(flag)
    {
        printf(",%d/%d", ac, bd);
    }
    else
    {
        flag = true;
        printf("%d/%d", ac, bd);
    }
    dfs(ac, bd, c, d);
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        flag = false;
        scanf("%d", &n);
        dfs(0, 1, 1, 1);
        printf("\n");
    }
    return 0;
}
