#include <iostream>
using namespace std;
int PD[3021][20];
int main()
{
    int x;
    while(cin>>x&&x)
    {
        int i,j,sum,w[20],n,m;
        sum=0;
        for (i=1;i<=x;i++)
        {
            cin>>w[i];
            sum+=w[i];
        }
        memset(PD,0,sizeof (PD));
        m=sum/2;
        for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
             else if(PD[i][j-1]<PD[i-w[j]][j-1]+w[j])
             PD[i][j]=PD[i-w[j]][j-1]+w[j];
             else
             PD[i][j]=PD[i][j-1];
        }
        m=sum-2*PD[m][n];
        if (m<0)
        m=-m;
        cout<<m<<endl;
    }
}
    
