#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<functional>
#include<climits>
using namespace std;

int source;
int sink;
const static int N = 205;
int mat[N][N];  //残留网络，初始为原图
int d[N];       //标号
int num[N];     //num[i]表示标号为i的顶点数有多少
bool vst[N];
int pre[N];
int n,m;
void ini_d() //BFS计算标号，汇点t标号为0
{
    int k;
    queue<int> q;
    memset(d,-1,sizeof(d));
    memset(num,0,sizeof(num));
    q.push(sink);
    d[sink]=0;
    num[0]=1;
    while (!q.empty())
    {
        k=q.front();
        q.pop();
        for (int i=0; i<n; i++)
        {
            if (d[i]>=n && mat[i][k]>0)
            {
                d[i]=d[k]+1;
                q.push(i);
                num[d[i]]++;
            }
        }
    }
}

int findAlowArc(int i)       //从i出发寻找允许弧
{
    for (int j=0; j<n; j++)
    {
        if (mat[i][j]>0 && d[i]==d[j]+1)
            return j;
    }
    return -1;
}
int reLable(int i)         //重新标号
{
    int mn=n;
    for (int j=0; j<n; j++)
        if (mat[i][j]>0)
            mn=min(mn,d[j]+1);
    return mn==n?n:mn;
}
void MaxFlow()      //从源点s出发的最大流
{
    ini_d(); // BFS计算标号，汇点t标号为0
    int flow=0,i=source,j;
    int delta;              //增量
    memset(pre,-1,sizeof(pre));
    while (d[source]<n)
    {
        j=findAlowArc(i);
        if (j>=0)
        {
            pre[j]=i;
            i=j;
            if (i==sink)           //更新残留网络
            {
                delta=INT_MAX;
                for (i=sink; i!=source; i=pre[i])
                    delta=min(delta,mat[pre[i]][i]);
                for (i=sink; i!=source; i=pre[i])
                {
                        mat[pre[i]][i] -= delta;
                        mat[i][pre[i]] += delta;
                }
                flow += delta;
            }
        }
        else
        {
            int x=reLable(i);       //重新标号
            num[x]++;
            num[d[i]]--;
            if (num[d[i]]==0)
            {
                printf("%d\n",flow);     //间隙优化
                return;
            }
            d[i]=x;
            if (i!=source)
                i=pre[i];
        }
    }
    printf("%d\n",flow);
}
// n 顶点 m 边
int main()
{
    //freopen("mf1.in","r",stdin);
   // freopen("my.txt","w",stdout);
    int s, e, c;
    while(scanf("%d %d",&n,&m) != EOF)
    {
        source = 0;
        sink = m-1;
        memset(mat,0,sizeof(mat));
        for(int i=0; i < n; i++)
        {
            scanf("%d %d %d",&s,&e,&c);
            mat[s-1][e-1] += c;
        }
        MaxFlow();
    }
    return 0;
}
