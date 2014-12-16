#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
using namespace std;

const int N = 1008;
const int M = 5008;
const int INF = 0xfffffff;
int L,P;
struct map
{
    int e,d;
    map(){}
    map(int a,int b):e(a),d(b){}
};

double fun[N];
vector <map> g[M];
double d[N];
bool hash[N];
int visit[N];

int spfa_dis(double val)
{
    int i,j;
    queue <int> q;
    for(i=0;i<=L;i++)
    {
        d[i] = INF;
        hash[i] = 0;
        visit[i] = 0;
    }
    d[0] = 0;
    hash[0] = 1;
    q.push(0);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        hash[u] = 0;

        for(i=0;i<g[u].size();i++)
            if( (d[g[u][i].e] > d[u] + val * g[u][i].d - fun[g[u][i].e]))
            {
                d[g[u][i].e] = d[u] + val * g[u][i].d - fun[g[u][i].e];
                if(!hash[g[u][i].e])
                {
                    q.push(g[u][i].e);
                    hash[g[u][i].e] = 1;
                    visit[g[u][i].e]++;
                    if(visit[g[u][i].e] >= L) return 1;
                }
            }
    }
    return 0;
}

double solve()
{
    int i;
    double max;
    double l=0,r=N*N*N;
    while(l<=r)
    {
        double mid = (l + r) / 2;
        if(spfa_dis(mid/1000))
        {
            l = mid + 1;
            max = mid;
        }
        else
            r = mid - 1;
    }
    return max;
}

int main()
{
    int x,y,p,i;
    double ans;
    while(scanf("%d%d",&L,&P)!=EOF)
    {
        for(i=0;i<L;i++)
        {
            scanf("%lf",&fun[i]);
            g[i].clear();
        }
        for(i=0;i<P;i++)
        {
            scanf("%d%d%d",&x,&y,&p);
            x--;y--;
            g[x].push_back(map(y,p));
        }

        ans = solve();
        if(((int)ans % 10) > 4)
            ans = ans + 10 - (int)ans % 10;
        printf("%.2lf\n",ans / 1000.0);
    }
    return 0;
}
