#include <stdio.h>
#include <malloc.h>
int main()
{
    int n;
    scanf("%d",&n);
    int **matrix;
    while(n!=0)
    {
     matrix=(int **)malloc(n*sizeof(int *));  
     int i;
     for(i=0;i<n;i++)  
     matrix[i]=(int *)malloc(n*sizeof(int));
     int m;
     int t; 
     for (m=0;m<n;m++)
     {
         for(t=0;t<n;t++)
         {
                        scanf("%d",&matrix[m][t]);
                        }
     }
    int *check_column;
    check_column=(int *) malloc(n*sizeof(int));
    int *check_row;
    check_row=(int *)malloc(n*sizeof(int));
    for(m=0;m<n;m++)
    {
                    check_column[m]=0;
                    check_row[m]=0;
                    }
    for (m=0;m<n;m++)
    {
        for(t=0;t<n;t++)
        {
                        check_column[m]=check_column[m]+matrix[m][t];
                        check_row[m]=check_row[m]+matrix[t][m];
                        
        }
    }
    int c_flag=0;
    int r_flag=0;
    int column_row[2]={0,0};
    for (m=0;m<n;m++)
    {
        if((check_column[m]%2)!=0)
        {
                                  c_flag++;
                                  column_row[0]=m;
                                  }
        if((check_row[m]%2)!=0)
        {
                               r_flag++;
                               column_row[1]=m;
                               }
    }
    if((c_flag==0)&&(r_flag==0))
    {
                                printf("%s\n","OK");
                                }
                                
    else if((c_flag==1)&&(r_flag==1))
    {
         printf("Change bit (%d,%d)\n",column_row[0]+1,column_row[1]+1);
         }
         
    else
    {
        printf("Corrupt\n");
        }
    scanf("%d",&n);
    }
    return 0;
}
