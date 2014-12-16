#include<stdio.h>
int c[200][600],m[600];
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        if(a==0&&b==0)
        break;
        int i,j;
        int s=0;
        for(i=0;i<b;i++)
        for(j=0;j<a;j++)
        {
            scanf("%d",&c[i][j]);
        }
        for(j=0;j<b;j++)
        {
            m[j]=0;
            for(i=0;i<a;i++)
            {
                if(c[i][j]==0)
                m[j]=m[j]+1;
            }
        }
        for(j=0;j<b;j++)
        {
            if(m[j]==0)
            s=s+1;
        }
        if(s==0)
        printf("no\n");
        else if(s!=0)
        printf("yes\n");
    }
    return(0);
}
