#include <iostream>
#include <string>
using namespace std;
int sum[100];
int main()
{
    char First[100],Last[100];   
    while (cin>>First)
    {               
        memset(sum,0,sizeof(sum));
        int i,j,max=0,l,flag;
        for (i=0;i<strlen(First);i++)
        Last[strlen(First)-i-1]=First[i];               
        for (i=0;i<strlen(First);i++)
        for (j=0;j<strlen(First);j++)
        {
            flag=0;
            if (First[i]==Last[j])
            {                
                
                for (l=j;l<strlen(First);l++)
                {
                    if (First[i]==Last[l])
                    {
                        i++;
                        flag++;
                    }
                    else                                            
                    break;                                                           
                }
                i=i-1; 
                sum[flag]++;
                if (max<flag)
                max=flag;                                    
            }
        }
        
        printf ("%d %d\n",max,sum[max]);
    }
}
                    
                    
                    
                    
                    
                    
                    
                    
