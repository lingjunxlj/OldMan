#include <cstdio>
#define MAXN 2
int mat[100005][2],id[100005];
void floodfill(int n,int mat[][MAXN],int* id,int now,int tag)
{
    int i;
    for (id[now]=tag,i=0;i<n;i++)
    {
        if (!id[i]&&mat[now][i])
        floodfill(n,mat,id,i,tag);
    }
}
int find_components(int n,int mat[][MAXN],int* id)
{
    int ret,i;
    for (i=0;i<n;id[i++]=0);
    for (ret=i=0;i<n;i++)
    if (!id[i])
    floodfill(n,mat,id,i,++ret);
    return ret;
}
int main()
{
    int n,m,x,y,i;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        for (i=0;i<m;i++)
        {
            scanf("%d %d",&mat[i][0],&mat[i][1]);
        }
        int max;
        max=find_components(n,mat,0);
        printf("%d\n",max);
    }
}
