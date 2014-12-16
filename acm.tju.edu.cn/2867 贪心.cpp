#include<iostream>
#include<algorithm>
using namespace std;
#define N 10000
int dp[N+1];
struct node {
        double pro;
        int end;
        }a[10001];
int cmp(node a,node b)
{return a.end<b.end;}
int main()
{
    int sum;
    int i,j;
    int n;
    int pro;
    while(cin>>n,n!=0)
    {
         memset(dp,0,(N+1)*sizeof(int));

        for(i=0;i<n;i++)
        {
            cin>>a[i].pro>>a[i].end;
            a[i].end=a[i].pro+a[i].end;
        }
        sort(a,a+n,cmp);
        int k=1,sum;
        dp[0]=1;
        sum=dp[0];
        for (i=0;i<n;i++)
        {
            dp[i]=1;
            for(j=1;j<i;j++)
            {
                if(a[j].pro<=a[i].end)
                {
                    if(dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;
                }
            }
            if(dp[i]>sum)
            {
                sum=dp[i];
                n=i;
            }
        }
        cout<<sum<<endl;
    }
}

        
        

