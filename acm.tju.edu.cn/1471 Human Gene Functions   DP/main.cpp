#include <cstdio>
int map[200][200],dp[101][101];
char a[101],b[101];
int MAX(int a,int b,int c)
{
	return a>(c>b?c:b)?a:(c>b?c:b);
}
int main()
{
    map['A']['A']=5;
    map['A']['C']=map['C']['A']=-1;
    map['A']['G']=map['G']['A']=-2;
    map['A']['T']=map['T']['A']=-1;
    map['A'][' ']=map[' ']['A']=-3;
    map['C']['C']=5;
    map['C']['G']=map['G']['C']=-3;
    map['C']['T']=map['T']['C']=-2;
    map['C'][' ']=map[' ']['C']=-4;
    map['G']['G']=5;
    map['G']['T']=map['T']['G']=-2;
    map['G'][' ']=map[' ']['G']=-2;
    map['T']['T']=5;
    map['T'][' ']=map[' ']['T']=-1;
    int x;
    scanf("%d",&x);
    while (x--)
    {
        int n,m,i,j;
        scanf("%d %s",&n,a);
        scanf("%d %s",&m,b);
        dp[0][0]=0;
        for (i=1;i<=n;i++)
        dp[0][i]=dp[0][i-1]+map[' '][a[i-1]];
        for (i=1;i<=m;i++)
        dp[i][0]=dp[i-1][0]+map[' '][b[i-1]];
        for (i=1;i<=m;i++)
        for (j=1;j<=n;j++)
        {
            dp[i][j]=MAX(dp[i-1][j-1]+map[b[i-1]][a[j-1]],dp[i][j-1]+map[' '][a[j-1]],dp[i-1][j]+map[' '][b[i-1]]);
        }
        printf("%d\n",dp[m][n]);
    }
}





