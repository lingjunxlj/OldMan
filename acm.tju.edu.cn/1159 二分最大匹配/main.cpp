#include <cstdio>
#include <string>
int match[101];
int visit[101];
int map[101][101];
int Index[101];
int vn,vm,n,m,k;
char receptacle[501][31];
int plug[501][501];
int getid(char *s)
{
    int i;
    for(i=0;i<n;i++)
    if(strcmp(receptacle[i],s)==0)
    break;
    if(i==n)
    strcpy(receptacle[n++],s);
    return i;

}
bool find(int v)
{
    int i;
    for(i=0;i<vn;i++)
    {
        if(map[v][i]&&visit[i]==-1)
        {
            visit[i]=1;
            int t=match[i];
            match[i]=v;
            if(t==-1||find(t))
            return true;
            match[i]=t;
        }
    }
    return false;
}
int Max_Match()
{
    memset(match,-1,sizeof(match));
    int i,sum=0;
    for(i=0;i<vm;i++)
    {
        memset(visit,-1,sizeof(visit));
        if(find(i))
        sum++;
    }
    return sum;
}
int main()
{
    int i,j,k;
    char rstr[31],dstr[31];
    while(scanf("%d",&n)!=EOF)
    {
        vn=n;
        for(i=0;i<n;i++)
        scanf("%s",receptacle[i]);

        memset(map,0,sizeof(map));
        memset(plug,0,sizeof(plug));

        scanf("%d",&m);
        vm=m;
        for(i=0;i<m;i++)
        {
            scanf("%*s %s",dstr);
            Index[i]=getid(dstr);
        }


        scanf("%d",&k);
        for(i=0;i<k;i++)
        {
            scanf("%s %s",rstr,dstr);
            int id_1=getid(rstr);
            int id_2=getid(dstr);
            plug[id_1][id_2]=1;
        }
        for(k=0;k<n;k++)
        for(i=0;i<n;i++)
        {
            if(i==k)
            {
                plug[i][k]=1;
                continue;
            }
            if(plug[i][k])
            for(j=0;j<n;j++)
            {
                if(plug[k][j])
                plug[i][j]=1;
            }
        }
        for(i=0;i<=vm;i++)
        for(j=0;j<=vn;j++)
        {
            if(plug[Index[i]][j])
            map[i][j]=1;
        }
        int Max=Max_Match();
        printf("%d\n",m-Max);
    }
}
