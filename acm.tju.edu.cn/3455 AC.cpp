#include<iostream>
using namespace std;
int bao[10100][30];
int main()
{
         int i,j,s,w[20],n,m;
         cin>>n;
         while(n--)
         {
                s=0;
                for(i=1;i<=10;i++)
                {
                    cin>>w[i];
                    s+=w[i];
                }
                for(i=0;i<=10;i++)
                bao[0][i]=0;
                m=s/2;
                for(i=0;i<=m;i++)
                bao[i][0]=0;
                for(i=1;i<=m;i++)
                for(j=1;j<=10;j++)
                {             
                    if(w[j]>i)                                      
                    bao[i][j]=bao[i][j-1];
                    else if(bao[i][j-1]<bao[i-w[j]][j-1]+w[j])
                    bao[i][j]=bao[i-w[j]][j-1]+w[j];
                    else 
                    bao[i][j]=bao[i][j-1];
                }
                    m=s-2*bao[m][10];
                          
                    if(m<0)
                    m=-m;
                    m=(s-m)/2;
                    cout<<m<<endl;
                
        }
         return 0;
}

