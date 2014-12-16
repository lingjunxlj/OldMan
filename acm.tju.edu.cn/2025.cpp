#include"stdio.h"
#include"math.h"
int p[2001];

int main()
{
    int n,c,n1;
    int i,j;
    int tol;
    int flag;
    while(scanf("%d%d",&n,&c)!=-1)
    {
    
    
        p[1]=1;
        tol=1;
        for(i=2;i<=3000;i++)
        {
            flag=1;
           for(j=2;j<=sqrt(i);j++)
           {
               if(i%j==0){flag=0;break;}
           }
         if(flag==0)continue;
         else if(i>n)break;
         else
         {
             tol++;
             p[tol]=i;
             
         }

        }
        

       
        printf("%d %d:",n,c);
        if(tol%2==0&&tol>=c*2)
        {
            for(i=1;i<=c*2;i++)
            {
                j=(tol-c*2)/2;
                printf(" %d",p[j+i]);

            }
            printf("\n\n");
        }

        if(tol%2==0&&tol<c*2)
        {
            for(j=1;j<=tol;j++)
                printf(" %d",p[j]);
            printf("\n\n");
        }

        if(tol%2==1&&tol>=c*2-1)
        {
            for(i=1;i<=c*2-1;i++)
            {
                j=(tol-c*2+1)/2;
                printf(" %d",p[i+j]);
            }
                printf("\n\n");
        }

        if(tol%2==1&&tol<c*2-1)
        {
            for(j=1;j<=tol;j++)
            {
                printf(" %d",p[j]);
            }
                printf("\n\n");
        }



    }
}
