
//x[j] = V[j] – ceil(D[j] / T) * T...奇怪， 怎么会 RE 
#include<iostream>//根据vi/di贪心
using namespace std;
int v[110];
int d[110];
struct aa
{
       double x;
       int y;
}a[110];
int mark[110];
bool cmp(aa p,aa q)
{
     return p.x<q.x;
}
int main()
{
    int n,t;
    int i;
    int j,k;//biao ji
    while(scanf("%d%d",&n,&t)!=EOF)
    {
          j=0;
          for(i=1;i<=n;i++)
          {
                scanf("%d%d",&v[i],&d[i]);
                if(d[i]>t) j=1;
                else{
                    a[i].x=((double)v[i])/d[i];
                    a[i].y=i;
                    mark[i]=0;
                }
          }
          if(j==1) {printf("The zombies eat your brains!\n"); }
          else {
               sort(a+1,a+n+1,cmp);
               k=0;
               for(i=1;i<=n;i++)
               {
                    for(j=1;j<=n;j++)
                    {
                         if(mark[j]==0) v[j]-=t;
                         if(v[j]<0) 
                         {
                             printf("The zombies eat your brains!\n");
                             k=1;
                             i=n+1;
                             break;
                         }
                         else mark[a[i].y]=1;
                    }
               }
               if(k!=1)
               {
                     for(i=1;i<=n;i++)
                     {
                           printf("%d ",a[i].y);
                     }
                     printf("\n");
               }
          }
    }
    return 0;
}

