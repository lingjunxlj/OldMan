#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define lowbit(x) (x & (-x))
int MAX;
int c[100005],sim[100005];
int N;
typedef struct node{
	int s,e;
	int order;
};
node ar[100005];
bool cmp(node x,node y){
	if(x.e != y.e)
		return x.e > y.e;
	else
		return y.s > x.s;
}
int updata(int x,int value){
	while(x < 100005){
		c[x] += value;
		x += lowbit(x);
	}
	return 0;
}
int sum(int x){
	int ans = 0;
	while(x > 0){
		ans += c[x];
		x -= lowbit(x);
	}
	return ans;
}
int m(int x,int y){
	return x > y ? x : y;
}
int main()
{
	int i,ts,te,key;
	while(scanf("%d",&N)!=EOF){
		if(N == 0) break;
		int MAX = 0;
		for(i = 1;i <= N; i++){
			scanf("%d%d",&ar[i].s,&ar[i].e);
			ar[i].s++; ar[i].e++;
			ar[i].order = i;
			MAX = m(m(ar[i].s,ar[i].e),MAX);
		}
		memset(c,0,sizeof(c));
		sort(ar+1,ar+1+N,cmp);
		key = sum(ar[1].s);
		sim[ar[1].order] = key;
		ts = ar[1].s; te = ar[1].e;
		updata(ar[1].s,1);
		for(i = 2;i <= N; i++){
			if(ar[i].s == ts && ar[i].e == te){
				sim[ar[i].order] = sim[ar[i-1].order];
				updata(ar[i].s,1);
				continue;
			}
			ts = ar[i].s; te = ar[i].e;
			key = sum(ar[i].s);
			sim[ar[i].order] = key;
			updata(ar[i].s,1);
		}
		printf("%d",sim[1]);
		for(i = 2;i <= N; i++)
			printf(" %d",sim[i]);
		printf("\n");
	}
	return 0;
}
