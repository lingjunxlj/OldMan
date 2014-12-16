#include <cstdio>
#include <cmath>
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 55555;
long long sum[maxn<<2];
long long num[maxn<<2];
int isone[max<<2];
void PushUP(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];

}
void build(int l,int r,int rt)
{
	if (l == r)
	{
		scanf("%I64d",&sum[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int l,int r,int rt)
{
	if (isone[rt] == 1)
        return;
	if (l == r)
	{
		sum[rt] = (long long)(sqrt((double)sum[rt]) + 1e-8);
		isone[rt] = sum[rt] == r - l + 1;
		return ;
	}
	sum[rt] += add;
	int m = (l + r) >> 1;
	if (p <= m) update(p , add , lson);
	else update(p , add , rson);
	PushUP(rt);
	isone[rt] = sum[rt] == r - l + 1;
}
long long query(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		return sum[rt];
	}
	int m = (l + r) >> 1;
	long long ret = 0;
	if (L <= m)
        ret += query(L , R , lson);
	if (R > m)
        ret += query(L , R , rson);
	return ret;
}
int main()
{
	int n, x = 1, m;
	while(scanf("%d",&n) != EOF)
	{
	    top = 1;

        memset(isone, 0, sizeof(isone));
        printf("Case #%d:\n", x++);
		build(1,n ,1);


		scanf("%d", &m);
		while(m--)
		{
			int fg;
			scanf("%d", &fg);
			if (fg == 0)
			{
			    int a, b;
			    scanf("%d %d", &a, &b);
                update()
			}
			if (fg == 1)
            {
                int a, b;
			    scanf("%d %d", &a, &b);
			    printf("%I64d\n",query(a,b,1,n,1));
			    //printf("1\n");

            }
		}
		printf("\n");
	}
	return 0;
}
