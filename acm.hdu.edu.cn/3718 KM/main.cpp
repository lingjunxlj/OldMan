#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <iostream>
using namespace std;
#define inf 199999999
int link[30],lx[30],ly[30];
bool x[30],y[30];
int net[30][30];
char s[10005];
int n, m, k;
bool dfs(int u)
{
    int i;
    x[u]=true;
    for(i=0;i<26;i++)
    {
        if(lx[u]+ly[i]==net[u][i]&&!y[i])
        {
            y[i]=true;
            if(link[i]==-1||dfs(link[i]))
            {
                link[i]=u;
                return true;
            }
        }
    }
    return false;
}
int KM()
{
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(link,-1,sizeof(link));
    memset(ly,0,sizeof(ly));
    for(int ii = 0; ii < 30; ii++)
        lx[ii] = inf;
    for(int k = 0; k < 26; k++)
    {
        while(1)
        {
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
            if(dfs(k))
                break;
            int d = inf;
            for(int ii = 0; ii < 26; ii++)
            {
                if(x[ii])
                {
                    for(int jj = 0; jj < 26; jj++)
                    {
                        if(!y[jj] && lx[ii] + ly[jj] - net[ii][jj] < d)
                            d = lx[ii] + ly[jj] - net[ii][jj];
                    }
                }
            }
            for(int ii = 0; ii < 26; ii++)
                if(x[ii])
                    lx[ii] = lx[ii] - d;
            for(int ii = 0; ii < 26; ii++)
                if(y[ii])
                    ly[ii] = ly[ii] + d;
        }
    }
}
int main()
{
    int t;
    char temp[2];
    scanf("%d",&t);
    while(t--)
    {
        memset(s,'\0',sizeof(s));
        scanf("%d%d%d",&n,&k,&m);
        for(int i = 1; i <= n; i++)
        {
            scanf("%s",temp);
            s[i]=temp[0];
        }
        for(int i=1;i<=m;i++)
        {
            memset(net,0,sizeof(net));
            for(int j = 1; j <= n; j++)
            {
                scanf("%s", temp);
                net[s[j]-'A'][temp[0]-'A']++;
            }
            KM();
            int ans = 0;
            for(int j = 1;j <= n;j++)
                ans += net[link[j]][link[j]];
            printf("%.4lf\n", (double)ans/(double)n);
        }
    }

}
