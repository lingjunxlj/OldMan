#include <cstdio>
#include <string>
char str[31][31],str1[31],str2[31];
double change[31][31];
int n;
int cmp(char st[])
{
    int i;
    for(i=0;i<n;i++)
    {
        if(!strcmp(str[i],st))
        return i;
    }
    return -1;
}
void FLOYD(double change[][31])
{
     int i,j,k;
     for(i=0;i<n;i++)
     {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                if(change[j][i] * change[i][k] > change[j][k])
                change[j][k] = change[j][i] * change[i][k];
            }
        }
     }
}

int main()
{
    int m, i, flag, t = 0;
    double ratio;
    while(scanf("%d",&n))
    {

        if(n==0)
        break;
        t++;
        flag=0;
        memset(change,0,sizeof(change));
        for(i=0;i<n;i++)
        scanf("%s",str[i]);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s",str1);
            scanf("%lf\n",&ratio);
            scanf("%s",str2);

            change[cmp(str1)][cmp(str2)]=ratio;
        }

        FLOYD(change);
        for(i=0;i<n;i++)
        {
            if(change[i][i]>1)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        printf("Case %d: Yes\n",t);
        else
        printf("Case %d: No\n",t);
    }

}
