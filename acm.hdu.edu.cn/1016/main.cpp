#include <iostream>
#include <cstdio>
using namespace std;

int n,cnt = 1;
int vis[21],A[21];
int primelist[38] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1};

void dfs(int cur)
{
	if(cur == n && primelist[A[0] + A[n-1]])
	{
		cout << A[0] ;
		for(int i = 1;i < n;++i)
			cout << " "<< A[i];
		cout <<endl;
	}
	else
        for(int i = 2;i <= n;++i)
            if(!vis[i] && primelist[i + A[cur-1]])
            {
                A[cur] = i;
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0;
            }
}

int main()
{
	A[0] = 1;
	while(cin >> n)
	{
		memset(vis,0,sizeof(vis));
		cout << "Case " << cnt++ <<":\n";
		dfs(1);
		cout << endl;
	}

	return 0;
}
