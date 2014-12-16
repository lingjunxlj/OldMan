#include <cstdio>
#include <cstring>
#define N 9
bool row[N][10],column[N][10],square[N][10];
unsigned int map[N][N];
inline unsigned int square_index(unsigned int a,unsigned int b)
{
	return a/3*3+b/3;
}
inline bool check(unsigned int a, unsigned int b)
{
    unsigned int x = 0;
    for (unsigned int i = 0; i < 9; i++)
        if (map[a][i] == map[a][b] && i != b)
            return 0;
    for (unsigned int i = 0; i < 9; i++)
        if (map[i][b] == map[a][b] && i != a)
            return 0;
    for (unsigned int i = a/3*3; i < a/3*3+3; i++)
        for (unsigned int j = b/3*3; j < b/3*3+3; j++)
            if (map[i][j] == map[a][b] && i != a && j != b)
                return 0;
    return 1;
}
inline void flag_position(unsigned int a,unsigned int b)
{
	row[a][map[a][b]]=!row[a][map[a][b]];
	column[b][map[a][b]]=!column[b][map[a][b]];
	square[square_index(a,b)][map[a][b]]=!square[square_index(a,b)][map[a][b]];
}
inline bool check_position(unsigned int a,unsigned int b,unsigned int value)
{
	if(row[a][value]||column[b][value]||square[square_index(a,b)][value]) return false;
	return true;
}
bool DFS(unsigned int k)
{
	if(k==-1) return true;
	unsigned int a=k/N,b=k%N;
	if(map[a][b]) return DFS(k-1);
	else
	{
		for(unsigned int i=1;i<=N;i++)
		{
			if(check_position(a,b,i))
			{
				map[a][b]=i;
				flag_position(a,b);
				if(DFS(k-1)) return true;
				flag_position(a,b);
			}
		}
		map[a][b]=0;
	}
	return false;
}
int main()
{
	unsigned int n;
	char temp_str[N+1];
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		memset(row,0,sizeof(row));
		memset(column,0,sizeof(column));
		memset(square,0,sizeof(square));
		for(unsigned int i=0;i<N + 1;i++)
		{
			gets(temp_str);
			if(i != N)
                for(unsigned int j=0;j<N;j++)
                {
				    if (temp_str[j] == '?')
                        map[i][j] = 0;
                    else
                        map[i][j]=temp_str[j]-'0';
                    if(map[i][j])
                        flag_position(i,j);
                }
		}
		bool fg = 1;
		for(unsigned int i=0;i<N;i++)
		{
			for(unsigned int j=0;j<N;j++)
			{
				if(!check(i,j) && map[i][j] != 0)
				{
				    fg = 0;
				    goto a;
				}
			}
			//printf("\n");
		}
		a:
		if (fg == 0)
		{
		    printf("NO\n");
		    continue;
		}

		DFS(80);

        fg = 1;
		for(unsigned int i=0;i<N;i++)
		{
			for(unsigned int j=0;j<N;j++)
			{
				if(!check(i,j) )
				{
				    fg = 0;
				    goto b;
				}
			}
			//printf("\n");
		}
		b:
		if (fg == 1)
		printf("YES\n");
		else
		printf("NO\n");

	}
	return 0;
}
