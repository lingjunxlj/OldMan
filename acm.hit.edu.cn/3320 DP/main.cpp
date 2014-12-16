#include<iostream>
using namespace std;
const int N=105;
const int M=100005;
bool dp[N][M];
int amount[M];
int d[N];
int m[N];
bool J[M];
int judge(int n,int w){
     int i,j,count=0;
     memset(J,0,sizeof(J));
     for(j=1;j<=n;j++) dp[0][j]=0;
     for(i=0;i<=n;i++) dp[i][0]=1;
     for(i=1;i<=n;i++){
         memset(amount,0,sizeof(amount));
         for(j=1;j<=w;j++){
             dp[i][j]=dp[i-1][j];
             if(j>=d[i]&&dp[i][j-d[i]]&&amount[j-d[i]]+1<=m[i]){
                if(dp[i][j]==0)
                {
                   dp[i][j]=1;
                   amount[j]=amount[j-d[i]]+1;
                   if(J[j]==0) count++;
                   J[j]=1;
                }
             }
         }
     }
     return count;
}

int main()
{
    int n,w,i,result;
    while(cin>>n>>w){
          if(!n&&!w) break;
          for(i=1;i<=n;i++) cin>>d[i];
          for(i=1;i<=n;i++) cin>>m[i];
          cout<<judge(n,w)<<endl;
    }
    return 0;
}
