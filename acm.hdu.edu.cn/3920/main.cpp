#include <cstdio>

#include <cstring>

#include <cmath>

using namespace std;



double g[105][105],dis[105];

int c[105][105];

int m,n,l,pre[105],inq[105],q[50005];



bool spfa(int n,int s,int t) {

  int l=1,r=2,x;

  memset(inq,false,sizeof inq);

  q[r]=s;inq[s]=true;

  for (int i=1;i<=n;++i) dis[i]=10000000;

  dis[s]=0;

  while (l!=r) {

    x=q[++l];l=(l<=50000)?l:1;

    for (int i=1;i<=n;++i)

      if (c[x][i]>0 && !inq[i] && dis[i]>dis[x]+g[x][i]) {

        dis[i]=dis[x]+g[x][i];q[++r]=i;r=(r<=50000)?r:1;inq[i]=true;pre[i]=x;

      }

    inq[x]=false;

  }

  return (dis[t]<10000000);

}



#define min(A,B) ((A)<(B)?(A):(B))

double cflow(int n,int s,int t) {

  double ret=0;

  int delta;

  while (spfa(n,s,t)) {

    delta=10000000;

    for (int u=t;u!=s;u=pre[u]) delta=min(delta,c[pre[u]][u]);

    for (int u=t;u!=s;u=pre[u]) c[pre[u]][u]=-=delta;

    ret+=dis[t]*delta;

  }

  return ret;

}
