#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=50001;
int pre[maxn],vis[maxn],task[maxn];
int find(int x)
{
    int ans=task[x],t=vis[x];
    int r=x;
    while(pre[r]!=r)
    {
        int pa=pre[r];
        if(t<vis[pa])
        {
            ans=task[pa];
            t=vis[pa];
        }
        r=pre[r];
    }
    return ans;

}
int main()
{
    int cas,Cas=0;
    cin>>cas;
    while(cas--)
    {
        int n,v,u;
        cin>>n;
        memset(vis,0,sizeof(vis));
        memset(task,-1,sizeof(task));
        for(int i=1;i<=n;i++)pre[i]=i;
        for(int i=1;i<n;i++)
        {
            cin>>v>>u;
            pre[v]=u;
        }
        int num=0;
        int m,x,y;
        cin>>m;
        char ch;
        cout<<"Case #"<<++Cas<<":"<<endl;
        for(int i=0;i<m;i++)
        {
            cin>>ch;
            if(ch=='T')
            {
               cin>>x>>y;
               task[x]=y;
               vis[x]=++num;
            }
            else
            {
                cin>>x;
                cout<<find(x)<<endl;
            }
        }
    }
}
