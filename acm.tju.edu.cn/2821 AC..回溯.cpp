#include<iostream>
using namespace std;
int bao[3010][18];
int main()
{
         int i,j,s,w[20],n,m;
         while(cin>>n&&n)
         {
                s=0;
                for(i=1;i<=n;i++)
                {
                    cin>>w[i];
                    s+=w[i];
                }
                for(i=0;i<=n;i++)
                bao[0][i]=0;
                m=s/2;
                for(i=0;i<=m;i++)
                bao[i][0]=0;
                for(i=1;i<=m;i++)
                for(j=1;j<=n;j++)
                {             
                    if(w[j]>i)                                      
                    bao[i][j]=bao[i][j-1];
                    else if(bao[i][j-1]<bao[i-w[j]][j-1]+w[j])
                    bao[i][j]=bao[i-w[j]][j-1]+w[j];
                    else 
                    bao[i][j]=bao[i][j-1];
                }
                    m=s-2*bao[m][n];                          
                    if(m<0)
                    m=-m;
                    cout<<m<<endl;
                
        }
         return 0;
}
