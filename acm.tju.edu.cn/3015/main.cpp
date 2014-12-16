#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int dp[101][101],flag[101][101];
char str1[101][101],str2[101][101];
int fg,len1,len2;
void DFS(int x,int y)
{
    if (x<1||y<1)
    return;
    if (flag[x][y]==0)
    {
        DFS(x-1,y-1);
        if (!fg)
        printf ("%s", str1[x]);
        else
        printf (" %s", str1[x]);
        fg=1;
    }
    if (flag[x][y]==1)
    DFS(x-1,y);
    if (flag[x][y]==2)
    DFS(x,y-1);
}
int main()
{
    char temp[35];
    int i,j;
    while (scanf ("%s",temp) != EOF)
    {
        len1=len2=0;
        while (strcmp(temp,"#")!=0)
        {
            strcpy(str1[++len1],temp);
            scanf ("%s",temp);
        }
        scanf ("%s",temp);
        while (strcmp(temp,"#")!=0)
        {
            strcpy(str2[++len2],temp);
            scanf ("%s",temp);
        }
        memset(dp,0,sizeof(dp));
        for (i=1;i<=len1;i++)
        for (j=1;i<=len2;j++)
        {
            if (strcmp(str1[i],str2[j])==0)
            {
                dp[i][j]=dp[i-1][j-1]+1;
                flag[i][j]=0;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j]=dp[i-1][j];
                flag[i][j]=1;
            }
            else
            {
                dp[i][j]=dp[i][j-1];
                flag[i][j]=2;
            }
        }
        fg=0;
        DFS(len1,len2);
        printf("\n");
    }
}


