#include <cstdio>
#include <algorithm>
using namespace std;

#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
#define LL long long
const int maxn = 111111;
LL add[maxn<<2];
LL sum[maxn<<2];
LL num[maxn<<2];
void PushUp(int rt) {
	sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
LL getsum(int a, int b)
{
    LL sum = 0;
    for (int i = a; i <= b; i++)
    {
        if (num[i] <= 1)
            continue;
        else
            sum += (num[i] - (long long)floor((double)sqrt((double)num[i])));
    }
    return -sum;
}
void numupdate(int l, int r)
{
    for (int i = l; i <= r; i++)
        num[i] = (LL)sqrt(num[i]);
}
void PushDown(int rt,int l, int r)
{
	if (add[rt])
	{
		add[rt<<1] += add[rt];
		add[rt<<1|1] += add[rt];
		sum[rt<<1] += add[rt] * (m - (m >> 1));
		sum[rt<<1|1] += add[rt] * (m >> 1);
		add[rt] = 0;
	}
}
void build(int l,int r,int rt)
{
	add[rt] = 0;
	if (l == r)
	{
		scanf("%I64d",&sum[rt]);
		num[l] = sum[rt];
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L,int R,int l,int r,int rt)
{
	if (L <= l && r <= R)
	{
		add[rt] = 1;
		//sum[rt] += (LL)c * (r - l + 1);
		sum[rt] += (LL)getsum(r,l);
		num[]
		return ;
	}
	PushDown(rt , l, r);
	int m = (l + r) >> 1;
	if (L <= m) update(L , R , lson);
	if (m < R) update(L , R , rson);
	PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt) {
	if (L <= l && r <= R) {
		return sum[rt];
	}
	PushDown(rt , r - l + 1);
	int m = (l + r) >> 1;
	LL ret = 0;
	if (L <= m) ret += query(L , R , lson);
	if (m < R) ret += query(L , R , rson);
	return ret;
}
int main() {
	int n, x = 1, m;
	while(scanf("%d",&n) != EOF)
	{
	    top = 1;
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
			    update(a , b , 1 , n , 1);
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
