#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1002
using namespace std;
int low[M],dep[M],f[M];
bool flag[M],map[M][M];
int n,depth,root,cont;
int min(int a,int b){
	return a<b?a:b;
}
void dfs(int m){
	dep[m] = depth;
	low[m] = depth;
	flag[m] = true;
	depth++;
	int i,j;
	for(i = 1;i <= n; i++){
		if(map[m][i]){
			if(!flag[i]){
				dfs(i);
				low[m] = min(low[m],low[i]);
				if(low[i] >= dep[m] && m != 1)
					f[m] ++;
				else if(m == 1)
					root ++;
			}
			else
				low[m] = min(low[m],dep[i]);
		}
	}
}
int main()
{
	int i,j,k;
	while(scanf("%d",&n),n){
		memset(map,false,sizeof(map));
		memset(f,0,sizeof(f));
		memset(low,0,sizeof(low));
		memset(flag,false,sizeof(flag));
		while(scanf("%d",&k),k){
			while(getchar() != '\n'){
				scanf("%d",&j);
				map[k][j] = map[j][k] = true;
			}
		}
		depth = 1; root = 0; cont = 0;
		dfs(1);
		int ans = 0;
		if(root > 1){
			ans ++;
			f[1]= 1;
		}
		for(i = 2;i <= n; i++)
			if(f[i]) ans ++;
		printf("%d",ans);
		if(ans > 0){
			int tep = 0; printf(" ");
			for(i = 1;i <= n; i++)
				if(f[i]){
					tep ++;
					printf("%d",i);
					if(tep != ans) printf(" ");
					else printf("\n");
				}
		}
		else printf("\n");
	}
}
