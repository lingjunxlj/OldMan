#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int map[1001][1001];
int dist[1001],dp[1001];
void dijkstra(int v)
{
    int i,j,mins,index;
    int s[n + 1];
    for(i=1;i<=n;i++)
    {
        dist[i] = map[i][v];
        s[i] = 0;
    }
    dist[v] = 0;
    s[v] = 1;
    for(i=1;i<n;i++)
    {
        mins = 2000000;
        for(j=1;j<=n;j++)
        {
            if(s[j]==0 && dist[j]<mins)
            {
                mins = dist[j];
                index = j;
            }
        }
        if(mins == 2000000)
            break;
        s[index] = 1;
        for(j=1;j<=n;j++)
        {
            if(s[j]==0 && dist[j]>dist[index]+map[j][index])
                dist[j] = dist[index]+map[j][index];
        }
    }
}

int dfs(int v)
{
    if(dp[v] != -1)
        return dp[v];
    if(v == 2)
        return 1;
    int i,temp,sum=0;
    for(i=1;i<=n;i++)
    {
        if(map[v][i]!=2000000 && dist[v] > dist[i])
        {
            temp = dfs(i);
            sum += temp;
        }
    }
    dp[v] = sum;
    return sum;
}

int main()
{
    while(cin>>n && n)
    {
        int i,j,d,m;
        cin>>m;
        for(i=1;i<=n;i++)
        {
            dp[i] = -1;
            for(j=1;j<=n;j++)
                map[i][j] = 2000000;
        }
        while(m--)
        {
            scanf("%d%d%d",&i,&j,&d);
            map[i][j] = map[j][i] = d;
        }

        dijkstra(2);
        dfs(1);
        cout<<dp[1]<<endl;
    }
    return 0;
}
