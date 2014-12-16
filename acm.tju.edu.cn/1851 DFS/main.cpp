#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 9
bool row[N][10],column[N][10],square[N][10];
int map[N][N];
int square_index(int a,int b)
{
	return a/3*3+b/3;
}
void flag_position(int a,int b)
{
	row[a][map[a][b]]=!row[a][map[a][b]];
	column[b][map[a][b]]=!column[b][map[a][b]];
	square[square_index(a,b)][map[a][b]]=!square[square_index(a,b)][map[a][b]];
}
bool check_position(int a,int b,int value)
{
	if(row[a][value]||column[b][value]||square[square_index(a,b)][value]) return false;
	return true;
}
bool DFS(int k)
{
	if(k==81) return true;
	int a=k/N,b=k%N;
	if(map[a][b]) return DFS(k+1);
	else
	{
		for(int i=1;i<=N;i++)
		{
			if(check_position(a,b,i))
			{
				map[a][b]=i;
				flag_position(a,b);
				if(DFS(k+1)) return true;
				flag_position(a,b);
			}
		}
		map[a][b]=0;
	}
	return false;
}
int main()
{
	int n;
	char temp_str[N+1];
	scanf("%d",&n);
	while(n--)
	{
		memset(row,0,sizeof(row));
		memset(column,0,sizeof(column));
		memset(square,0,sizeof(square));
		for(int i=0;i<N;i++)
		{
			scanf("%s",temp_str);
			for(int j=0;j<N;j++)
			{
				map[i][j]=temp_str[j]-'0';
				if(map[i][j])
				{
					flag_position(i,j);
				}
			}
		}
		DFS(0);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				printf("%d",map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
