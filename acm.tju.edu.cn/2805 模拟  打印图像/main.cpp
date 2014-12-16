#include<stdio.h>
#include<math.h>
int a[100000]={0};
int main()
{
    int i,j,k,l,m,n;
    a[1]=1;
    for(k=1;k<=10;k++)
    {
        i=pow(3,k);
        j=pow(3,k-1);
        for(l=1;l<=j;l++)
            a[i--]=a[l];

    }
    while(scanf("%d",&n)!=EOF)
    {
        m=pow(3,n);
        for(i=1;i<=m;i++)
            if(a[i])
                printf("@");
            else
                printf(" ");
        printf("\n");
    }
    return 0;

}
