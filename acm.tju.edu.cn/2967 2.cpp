#include<iostream>
using namespace std;
int main()
{
    int i,j,k,l,m,n,s;
    while(cin>>k)
    {
             if(k<0)
                    break;
             if(k==1)
             {
                    cin>>n;
                    m=n-1;
                    s=1;
                    for(i=1;i<=n;i++)
                    {
                            for(j=1;j<=m;j++)
                                    printf(" ");
                            m--;
                            for(l=1;l<=s;l++)
                                    printf("*");
                                s=s+2;
                            printf("\n");
                    }
             }
             else if(k==2)
             {
                    cin>>n>>m;
                    s=m-1;
                    for(i=1;i<=m;i++)
                    {
              			for(j=1;j<=s;j++)
                        printf(" ");
                          s--;
                          for(j=1;j<=n;j++)
                                  printf("*");
                          printf("\n");
                    }
             }
             else 
            {
                    cin>>m>>n;
                    for(i=1;i<=n;i++)
                    {
                            for(j=1;j<=m;j++)
                                    printf("*");
                            printf("\n");
                    }
             }
             printf("\n");
    }
    return 0;
}
