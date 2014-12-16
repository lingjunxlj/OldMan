#include<stdio.h>
#define maxint 2139062143
int a[101][101],dist[101],n;
void spfa(int s)
{
    int q[101],v[101],h=0,t=1,x,i;//q为队列,v为Boolean数组,表示结点是否在队列中,h为头指针,t为尾指针
　　memset(q,0,sizeof(q));
　　memset(v,0,sizeof(v));
　　memset(dist,127,sizeof(dist));//置dist数组为 maxint(+∞),下同
　　dist[s]=0;
　　q[t]=s;v[s]=1;
　　while(h!=t)//本来是h<t,但这不是循环队列么,不能这么干的...
　　{
　　      h=(h+1)%(n+1);//这里不能%n否则队满和队空状态一样
　　      x=q[h];
　　      v[x]=0;
　　      for(i=1;i<=n;i++)
　　      if(dist[i]-a[x][i]>dist[x])//这里本来为 dist[i]>dist[x]+a[x][i],但这样会越界的,因为后两者加起来太大
　　      {
　　             dist[i]=dist[x]+a[x][i];
　　             if(!v[i])
　　             {
　　                 t=(t+1)%(n+1)/*同上*/;q[t]=i;v[i]=1;
　　             }
　　       }
　　  }
}
int main()
{
    int m,s,t,i;
　　scanf("%d%d",&n,&m);
　　scanf("%d%d",&s,&t);
　　memset(a,127,sizeof(a));
　　for(i=1;i<=m;i++)
　　{
　　     int x,y,z;
　　     scanf("%d%d%d",&x,&y,&z);
　　     a[x][y]=z;
　　     a[y][x]=z;
　　}
　　spfa(s);
　　printf("%d",dist[t]);
　　system("pause");
　　return 0;
}
