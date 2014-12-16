#include <cstdio>
int main ()
{
    int i;
    int n,num,flag;
    int up,down;
    int a[31];
    double len1,len2;
    for(;scanf("%d",&a[0])!=EOF;)
    {
        if(a[0]==0) return 1;
        for(i=1;;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==0) break;
        }
        n=i;
        num=up=down=0;
        len1=len2=0.0;
        flag=0;

        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
            {
                if(flag==0)
                    num++;
                else
                    if(flag==1)
                        len1+=1.0;
                    else
                        len2+=1.0;
            }
            else
                if(a[i]>a[i-1])
                {
                    len1+=(double)(num+1);
                    if(flag==2) up++;
                    if(flag==0) up++;
                    flag=1;
                    num=0;
                }
                else
                {
                    len2+=(double)(num+1);
                    if(flag==1) down++;
                    if(flag==0) down++;
                    flag=2;
                    num=0;
                }
        }

        if(up!=0)
        len1=len1/(double)up;

        if(down!=0)
        len2=len2/(double)down;
        printf("Nr values = %d:  %.6lf %.6lf\n",n,len1,len2);
    }

}
