#include<iostream>

using namespace std;
int a[301];
int r[1000001];
int main()
{
    int t,n,c,i,k,flag;
    scanf("%d",&t);
    while(t--)
    {              
          scanf("%d",&n);
          for(i=1;i<=n;i++)
          {
              scanf("%d",&a[i]);             
          }
          for(k=n;;k++)
          {
              memset(r,-1,sizeof(int)*k);
              c=0;
              for(i=1;i<=n;i++)
              {
                  if(r[a[i]%k]!=-1)
				  break;
                  r[a[i]%k]=a[i]%k;
                  c++;             
              }
              if(c==n)break;             
           }            
          printf("%d\n",k);      
          }
    return 0;
    }
 
