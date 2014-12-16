#include <cstdio>
#include <string>
#define maxn 505
int job_num, ans, sy[maxn], cy[maxn], g[maxn][maxn];
int path(int u)
{
    int v,i;
    for(v = 0;v < job_num; v++)
        if(g[u][v]>0 && !sy[v]){
            sy[v]=1;
            if(!cy[v] || path(cy[v])){
                cy[v] = u;
                return 1;
            }
        }
      return 0;
}
int main()
{
    int i, j, k, l, p;
    while (scanf("%d",&job_num)!=EOF){
        memset(g,0,sizeof(g));
        for (i=0;i<job_num;i++){
            scanf("%d: (%d)",&l,&k);
            while (k--){
                scanf("%d",&p);
                g[l][p]=1;
            }
        }
        ans = 0;
        memset(cy, 0, sizeof(cy));
        for(i = 0;i < job_num; i++){
            memset(sy, 0, sizeof(sy));
            ans += path(i);
        }
        printf ("%d\n",job_num-ans/2);
    }
}
