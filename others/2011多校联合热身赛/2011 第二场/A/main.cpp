#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
using namespace std;
const int inf=1000000000;
const double pi=acos(-1.0);
const double eps=1e-8;
const int maxn=1000010;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
inline void fill(int *a,int b,int c){
for (int i=0;i<c/4;i++,a++) *a=b;}
int n,m,s,q[maxn][4],road[maxn][2],a[maxn],b[maxn],c[maxn<<1],pos[maxn],
    en[maxn],f[maxn],w[maxn<<2],o[maxn<<2],next[maxn<<2],k,num=0,t;
int find(int x){
    if (x==f[x]) return x;
    return f[x]=find(f[x]),f[x];
}
void add(int x,int k){
    while (x<=n+n)
    {
        c[x]+=k;
        x+=x & -x;
    }
}
int getsum(int x){
    int s=0;
    while (x)
    {
        s+=c[x];
        x-=x & -x;
    }
    return s;
}
void dfs1(int x,int fa){
    for (int j=a[x];j;j=next[j])
        if (w[j]!=fa)
        {
            pos[w[j]]=++k;
            dfs1(w[j],x);
            en[w[j]]=++k;
            add(pos[w[j]],o[j]);
            add(en[w[j]],-o[j]);
        }
}
void dfs2(int x,int fa){
    f[x]=x;
    for (int j=b[x];j;j=next[j])
        if (pos[w[j]]<=pos[x]) q[o[j]][3]=find(w[j]);
    for (int j=a[x];j;j=next[j])
        if (w[j]!=fa) dfs2(w[j],x);
    f[x]=fa;
}
int main(){
    int i,j;
    freopen("pku2763.in","r",stdin);
    freopen("pku2763.out","w",stdout);
    scanf("%d%d%d",&n,&m,&s);
    for (i=1;i<n;i++)
    {
        scanf("%d%d%d",&j,&k,&t);
        road[i][0]=j; road[i][1]=k;
        w[++num]=k; o[num]=t; next[num]=a[j]; a[j]=num;
        w[++num]=j; o[num]=t; next[num]=a[k]; a[k]=num;
    }
    k=1; pos[1]=1; en[1]=n+n; dfs1(1,0);
    //for (i=1;i<=n;i++) cout<<pos[i]<<' '<<en[i]<<endl;
    //q[i][0]=1, 把点q[i][1]在树状数组中子树的值变为q[i][2]
    //q[i][1]=0, q[i][3]是q[i][1]和q[i][2]的lca
    for (i=1;i<=m;i++)
    {
        scanf("%d",&q[i][0]);
        if (q[i][0])
        {
            scanf("%d%d",&k,&q[i][2]);
            if (pos[road[k][0]]>pos[road[k][1]]) q[i][1]=road[k][0];
            else q[i][1]=road[k][1];
        } else
        {
            scanf("%d",&t);
            w[++num]=t; o[num]=i; next[num]=b[s]; b[s]=num;
            w[++num]=s; o[num]=i; next[num]=b[t]; b[t]=num;
            q[i][1]=s; q[i][2]=t; s=t;
        }
    }
    dfs2(1,0);
    for (i=1;i<=m;i++)
    {
        if (q[i][0])
        {
            j=pos[q[i][1]]; k=q[i][2]-(getsum(j)-getsum(j-1));
            add(j,k);
            add(en[q[i][1]],-k);
        } else
            printf("%d\n",getsum(pos[q[i][1]])+getsum(pos[q[i][2]])-
                          2*getsum(pos[q[i][3]]));
    }
    /*freopen("pku2763.in","w",stdout);
    cout<<"100000 100000 3"<<endl;
    //for (i=2;i<=500;i++) printf("%d %d %d\n",i,rand()%(i-1)+1,rand()%10000+1);
    //for (i=501;i<=100000;i++) printf("%d %d %d\n",i,rand()%500+1,rand()%10000+1);
    for (i=1;i<=100000;i++)
        if (rand() & 1) printf("0 %d\n",rand()%100000+1);
        else printf("1 %d %d\n",rand()%(99999)+1,rand()%10000+1);
    */
    return 0;
}
