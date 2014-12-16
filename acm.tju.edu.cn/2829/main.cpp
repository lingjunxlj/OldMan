#include <cstdio>
int main()
{
    int n,l;
    scanf("%d %d",&n,&l);
    int i=0,k=0;
    while (k!=n)
    {
        i++;
        int a,b,flag;
        flag=0;
        a=i;
        while (a)
        {
            b=a%10;
            a/=10;
            if (b==l)
            flag=1;
        }
        if (!flag)
        k++;
    }
    printf("%d\n",i);
}
