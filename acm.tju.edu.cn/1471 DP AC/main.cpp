#include <iostream>
using namespace std;
char a[105],b[105];
int  x[105],y[105];
int  score[200][200];
int table[5][5] =
{
	5,-1,-2,-1,-3,
	-1,5,-3,-2,-4,
	-2,-3,5,-2,-2,
	-1,-2,-2,5,-1,
	-3,-4,-2,-1,0
};
int atox(char c)
{
	switch(c)
	{
	case 'A' :
		return 0;
	case 'C' :
		return 1;
	case 'G' :
		return 2;
	case 'T' :
		return 3;
	default:
		return 4;
	}
}
int max3(int i,int j,int k)
{
	int temp = i>j?i:j;
	return temp>k ? temp : k;
}
int main()
{
	int i,j,k,n,m,t;
	int alen,blen;
	while (scanf("%d",&t)!=EOF)
	{
		while (t--)
		{
			memset(score,0,sizeof(score));
			memset(a,NULL,sizeof(a));
			memset(b,NULL,sizeof(b));
			memset(x,-1,sizeof(x));
			memset(y,-1,sizeof(y));

			scanf("%d",&alen);
			scanf("%s",&a);
			for (i=1;i<=alen;i++)
			{
				x[i] = atox(a[i-1]);
			}
			scanf("%d",&blen);
			scanf("%s",&b);
			for (j=1;j<=blen;j++)
			{
				y[j] = atox(b[j-1]);
			}
			score[0][0] = 0;
			for (i=1;i<=alen;i++)
			{
				score[0][i] = score[0][i-1] + table[x[i]][4];
			}
			for (j=1;j<=blen;j++)
			{
				score[j][0] = score[j-1][0] + table[4][y[j]];
			}

			for (i=1;i<=blen;i++)
			{
				for (j=1;j<=alen;j++)
				{
					score[i][j] = max3
					(
						score[i-1][j-1] + table[y[i]][x[j]] ,
						score[i-1][j] + table[4][y[i]] ,
						score[i][j-1] + table[x[j]][4]
					);
				}


			}
			printf("%d\n",score[blen][alen]);
		}
	}
	return 0;
}
