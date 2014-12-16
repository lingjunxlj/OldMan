#include <cstdio>
#include <cmath>
int main ()
{
    int n,m,y;
    while (scanf("%d %d %d",&n,&m,&y))
    {
        if (n==0&&m==0&&y==0)
        break;
        int sum=0;
        sum=(int)sqrt(y-m+1);
        printf ("%d\n",sum);

    }
}

