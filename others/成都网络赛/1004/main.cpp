#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Max=305;
int i,j,m,n,e,end;
int d[Max][Max],z[Max][Max];
int tt=0;
void dfs(int s, int t)
{
     int k;
     if(end==1)
         return ;
     if (z[s][t])
       return ;
     z[s][t]=true;
     //z[t][s]=true;
     for (k=1;k<=n;k++)
        if (d[s][k]+d[k][t]<d[s][t])
        {
           printf("Case %d: impossible\n",++tt);
           end=1;
           return ;
        }
        else if (k!=s && k!=t && d[s][k]+d[k][t]==d[s][t])
        {
			dfs(s,k);
            dfs(k,t);
            return;
        }
    e++;
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
		e=0;
		memset(z,false,sizeof(z));
		end=0;
        scanf("%d",&n);
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
              scanf("%d",&d[i][j]);
          for(i=1;i<=n;i++)
      	  	  for(j=1;j<=n;j++)
      		 	{
        			if(end==0);
        			    dfs(i,j);
        		}
        if(end==0)
            printf("Case %d: %d\n",++tt,e - n);
    	/*if (e>m)
      	printf("impossible\n");
    	else
      	{
         	for (i=1;i<=e;i++)
           		printf("%d %d %d\n",a[i],b[i],d[a[i]][b[i]]);
         	for (i=e+1;i<=m;i++)
          		 printf("%d %d %d\n",a[e],b[e],d[a[e]][b[e]]);
      	}*/
	}
}
