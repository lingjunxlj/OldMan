#include <stdio.h>
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int num[200],i=0,j;
        while (n)
        {
            num[i++]=n%2;
            n=n/2;
        }
        for (j=i-1;j>=0;j--)
        printf("%d",num[j]);
        printf("\n");
    }
}
