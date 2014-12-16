#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 30
using namespace std;
int mar[M];
int n,sum,m;
bool visit[M];
bool flag;
bool cmp(int a,int b)
{
    return a>b;
}
void dfs(int k,int sun,int N)
{
    if(sun==sum)
    {
        N++;
        if(N==3)
        {
            flag=true;
            return;
        }
        else
        {
            dfs(N,0,N);
        }
    }
    else
    {
        for(int i=k;i<m&&!flag;++i)
        {
            if(!visit[i]&&(mar[i]+sun)<=sum)
            {
                visit[i]=true;
                dfs(i+1,sun+mar[i],N);
                visit[i]=false;
            }
        }
    }
}
void input()
{
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            flag=false;
            sum=0;
            scanf("%d",&m);
            for(int i=0;i<m;++i)
            {
                scanf("%d",&mar[i]);
                sum+=mar[i];
                visit[i]=false;
            }
            if((sum%4)!=0)
            {
                printf("no\n");
                continue;
            }
            sort(mar,mar+m,cmp);
            if((sum%4)==0&&sum/4<mar[m-1])
            {
                printf("no\n");
                continue;
            }
            sum/=4;

            dfs(0,0,0);
            if(flag)
            printf("yes\n");
            else
            printf("no\n");
        }
    }
}
int main()
{
    input();
    return 0;
}
