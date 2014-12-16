#include <stdio.h>
int table(char a,char b)
{
	if(a==b)
		return 5;
	if(a=='A'&&b=='C'||a=='C'&&b=='A'||a=='A'&&b=='T'||a=='T'&&b=='A'||a=='T'&&b=='-'||a=='-'&&b=='T')
		return -1;
	if(a=='A'&&b=='G'||a=='G'&&b=='A'||a=='C'&&b=='T'||a=='T'&&b=='C'||a=='G'&&b=='-'||a=='-'&&b=='G'||a=='G'&&b=='T'||a=='T'&&b=='G')
		return -2;
	if(a=='G'&&b=='C'||a=='C'&&b=='G'||a=='A'&&b=='-'||a=='-'&&b=='A')
		return -3;
	else
		return -4;
}
int max(int a,int b,int c)
{
	return a>(c>b?c:b)?a:(c>b?c:b);
}

int main(void)
{
	int count,num1,num2,opt[101][101],i,j;
	char a[101],b[101];
	scanf("%d",&count);
	while(count-->0)
	{
		scanf("%d%s%d%s",&num1,a,&num2,b);
		opt[0][0] = 0;
		for(i=1;i<=num1;i++)
			opt[0][i] = opt[0][i-1]+table('-',a[i-1]);
		for(i=1;i<=num2;i++)
			opt[i][0] = opt[i-1][0]+table('-',b[i-1]);

		for(i=1;i<=num2;i++)
			for(j=1;j<=num1;j++)
				opt[i][j] = max(opt[i-1][j-1]+table(b[i-1],a[j-1]),opt[i][j-1]+table('-',a[j-1]),opt[i-1][j]+table('-',b[i-1]));

		printf("%d\n",opt[num2][num1]);

	}
	return 1;
}
