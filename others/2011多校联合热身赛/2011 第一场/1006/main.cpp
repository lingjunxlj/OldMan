#include<stdio.h>
int dl[10001];
int main()
{
    int chi,you,s,i,a,pang,j;
    scanf("%d",&chi);
    while(chi>0)
    {
        chi--;
        scanf("%d",&s);
        for(i=1;i<=s;i++)
        {
            scanf("%d",&a);
            dl[a]=i;
        }
        pang=0;
        for(i=1;i<s;i++)
        {
            if(i%2!=s%2)
            {
                j=s-1;
            }
            else
            {
                j=s;
            }
            for(;j>i;)
            {
                if((dl[(i+j)/2]<dl[j]&&dl[(i+j)/2]>dl[i])||(dl[(i+j)/2]>dl[j]&&dl[(i+j)/2]<dl[i]))
                {
                    printf("Y\n");  `
                    pang=1;
                    break;
                }
                j=j-2;
            }
            if(pang==1)
            {
                break;
            }
        }
        if(pang==0)
        printf("N\n");
    }
    return 0;
}
