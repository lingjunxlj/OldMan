#include<cstdio>
#include<cstring>
#define M 5050
struct node
{
    char a[5],b[5];
}c[M],d[M];
int ct,dt, v;
bool g[M][M],chk[M];
int a[M],b[M],n,m;
bool sp(int u)
{
	int v;
	for(v=1;v<=m;v++)
	{
		if(g[u][v] && !chk[v])
		{
			chk[v]=true;
			if(b[v]==-1 || sp(b[v]))
			{
				b[v]=u;
				a[u]=v;
				return true;
			}
		}
	}return false;
}
int match()
{
	int u,ret=0;
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	for(u=1;u<=n;u++)
	{
		if(a[u]==-1)
		{
			memset(chk,false,sizeof(chk));
			if(sp(u)) ret++;
		}
	}
	return ret;
}
int main()
{
    int cas;
    while(scanf("%d%d%d",&ct,&dt,&v) != EOF)
    {
        int cc,ddav;

        char ta[5],tb[5];
        ct=dt=0;
        for(int i=0; i<v; i++)
        {
            scanf("%s%s",ta,tb);
            if(ta[0]=='C')
            { //选猫不能选狗，选狗不能选猫，所以这之间产生矛盾
                ct++;
                strcpy(c[ct].a,ta);
                strcpy(c[ct].b,tb);
                //printf("%s %s\n",c[ct].a,c[ct].b);
            }else{
                dt++;
                strcpy(d[dt].a,ta);
                strcpy(d[dt].b,tb);
            }
        }
        memset(g,0,sizeof(g));
        for(int i=1; i<=ct; i++)
        {
            for(int j=1; j<=dt; j++)
            {
                if(strcmp(c[i].a,d[j].b)==0 || strcmp(c[i].b,d[j].a)==0 )
                    g[i][j]=1;
            }
        }
        n=ct, m=dt;
        printf("%d\n",v-match());
    }
}
