#include <iostream>
#include <cstdio>
#define MAX 10001
#define clr(x) memset(x, 0, sizeof(x));
using namespace std;
int degree[MAX],v[MAX];
bool check(int n)
{
    int rootcnt=0;
      for(int i=0;i<=n;i++)
      {
            if(v[i]&&degree[i]>1)
            return false;
            if(v[i]&&degree[i]==0)
            {
                  rootcnt++;
                  if(rootcnt>1)
                  return false;
            }
      }
      if(rootcnt==1)
      return true;
      return false;
}
int main()
{
    int a,b,mx_id,cases=0;
      while(scanf("%d %d",&a,&b)!= EOF)
      {
            if(a==-1&&b==-1) break;
            if(a==0&& b==0)
            {
                printf("Case %d is a tree.\n",++cases);
                continue;
            }
            mx_id=max(a,b);
            clr(v);
            clr(degree);
            degree[b]++;
            v[a]=v[b]=1;
            while(cin>>a>>b&&(a+b))
            {
                  mx_id=max(mx_id,a);
                  mx_id=max(mx_id,b);
                  v[a]=v[b]=1;
                  degree[b]++;
            }
            if(check(mx_id))
                  printf("Case %d is a tree.\n",++cases);
            else
                  printf("Case %d is not a tree.\n",++cases);
      }
}

