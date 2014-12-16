#include <iostream>
using namespace std;
#define MAX 101
#define INF 100000
int matrix[MAX][MAX];
int main()
{
	int i,j,k;
	int N,n;
	int adj;
	while(scanf("%d",&N),N)
	{

		for(i=1;i<=N;i++)
			for(j=1;j<=N;j++)
				if(i!=j)
					matrix[i][j]=INF;

		for(i=1;i<=N;i++)
		{
			scanf("%d",&n);
			for(j=1;j<=n;j++)
			{
				scanf("%d",&adj);
				scanf("%d",&matrix[i][adj]);
			}
		}
		for(k=1;k<=N;k++)
			for(i=1;i<=N;i++)
				for(j=1;j<=N;j++)
					if(matrix[i][k]+matrix[k][j]<matrix[i][j])
						matrix[i][j]=matrix[i][k]+matrix[k][j];


		int max,begin=0;
		int MinCost=INF;
		for(i=1;i<=N;i++)
		{
			max=-1;
			for(j=1;j<=N;j++)
				if(matrix[i][j]>max)
					max=matrix[i][j];
			if(max<MinCost)
			{
				begin=i;
				MinCost=max;
			}
		}
		if(MinCost!=INF)
			printf("%d %d\n",begin,MinCost);
		else
			printf("disjoint\n");
	}
	return 0;
}
