#include<stdio.h>
#define maxint 2139062143
int a[101][101],dist[101],n;
void spfa(int s)
{
    int q[101],v[101],h=0,t=1,x,i;//qΪ����,vΪBoolean����,��ʾ����Ƿ��ڶ�����,hΪͷָ��,tΪβָ��
����memset(q,0,sizeof(q));
����memset(v,0,sizeof(v));
����memset(dist,127,sizeof(dist));//��dist����Ϊ maxint(+��),��ͬ
����dist[s]=0;
����q[t]=s;v[s]=1;
����while(h!=t)//������h<t,���ⲻ��ѭ������ô,������ô�ɵ�...
����{
����      h=(h+1)%(n+1);//���ﲻ��%n��������Ͷӿ�״̬һ��
����      x=q[h];
����      v[x]=0;
����      for(i=1;i<=n;i++)
����      if(dist[i]-a[x][i]>dist[x])//���ﱾ��Ϊ dist[i]>dist[x]+a[x][i],��������Խ���,��Ϊ�����߼�����̫��
����      {
����             dist[i]=dist[x]+a[x][i];
����             if(!v[i])
����             {
����                 t=(t+1)%(n+1)/*ͬ��*/;q[t]=i;v[i]=1;
����             }
����       }
����  }
}
int main()
{
    int m,s,t,i;
����scanf("%d%d",&n,&m);
����scanf("%d%d",&s,&t);
����memset(a,127,sizeof(a));
����for(i=1;i<=m;i++)
����{
����     int x,y,z;
����     scanf("%d%d%d",&x,&y,&z);
����     a[x][y]=z;
����     a[y][x]=z;
����}
����spfa(s);
����printf("%d",dist[t]);
����system("pause");
����return 0;
}
