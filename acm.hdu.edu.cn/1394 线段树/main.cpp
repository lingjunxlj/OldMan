#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 5002;
int MAX[maxn<<2];

void PushUP(int rt) //求和
{
	MAX[rt] = MAX[rt<<1] + MAX[rt<<1|1];
}


void build(int l, int r, int rt)
{
	MAX[rt] = 0;
	if (l == r)
        return;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int sc,int l,int r,int rt)
{
	if (l == r)
	{
		MAX[rt] += sc;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m)
        update(p , sc , lson);
	else
        update(p , sc , rson);
	PushUP(rt);
}

int query(int L,int R,int l,int r,int rt) //求和
{
	if (L <= l && r <= R)
	{
		return MAX[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m)
        ret += query(L , R , lson);
	if (R > m)
        ret += query(L , R , rson);
	return ret;
}
int num[5002];
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        int sum = 0;
        build(0, n - 1, 1);
        //memset(MAX, 0, sizeof(MAX));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &num[i]);
            sum += query(num[i], n - 1, 0, n - 1, 1);
            update(num[i], 1, 0, n - 1, 1);
        }
        int ans = sum;
        for (int i = 0; i < n; i++)
        {
            sum += n - num[i] - num[i] - 1;
            ans = min(sum, ans);
        }
        printf("%d\n", ans);
    }
}
