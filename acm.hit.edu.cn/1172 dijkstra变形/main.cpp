#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;
const int MAX=201;
int map1[MAX][MAX],w[MAX],n;
bool flag[MAX];
void  dijkstra(int b,int e)
{
    int i,j,u,max,m;
    for (i=1;i<=n;i++)
    w[i]=map1[b][i];
    flag[b]=1;
    for (i=2;i<=n;i++)
    {
        u=0;
        max=0;
        for (j=1;j<=n;j++)
        {
            if (!flag[j]&&w[j]>max)
            {
                max=w[j];
                u=j;
            }
        }
        if (u==e)
        {
            printf("%d tons\n\n",max);
            return;
        }
        flag[u]=1;
        for (j=1;j<=n;j++)
        {
            if (!flag[j])
            {
                m=(max>map1[u][j]?map1[u][j]:max);
                if (m>w[j])
                w[j]=m;
            }
        }
    }
}
int main()
{
    int m,x=0;
    map<string,int> mp;
    while (cin>>n>>m)
    {
        memset(map1,0,sizeof(map1));
        memset(flag,0,sizeof(flag));
        string str1,str2;
        if (n==0&&m==0)
        break;
        x++;
        int k=1;
        while (m--)
        {

            int d;
            cin>>str1>>str2>>d;

            if (mp.find(str1)==mp.end())
            mp[str1]=k++;
            if (mp.find(str2)==mp.end())
            mp[str2]=k++;
            int i,j;
            i=mp[str1];
            j=mp[str2];
            if (d>map1[i][j])
            map1[i][j]=map1[j][i]=d;
        }
        cin>>str1>>str2;
        printf("Scenario #%d\n",x);
        dijkstra(mp[str1],mp[str2]);
    }
}



