#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn = 222222;
int MAX[maxn<<2];

void PushUP(int rt) //求最大值
{
	MAX[rt] = max(MAX[rt<<1] , MAX[rt<<1|1]);
}

void build(int l, int r, int rt)
{
	if (l == r)
	{
		scanf("%d", &MAX[rt]);
		return ;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUP(rt);
}
void update(int p,int sc,int l,int r,int rt)
{
	if (l == r)
	{
		MAX[rt] = sc;
		return ;
	}
	int m = (l + r) >> 1;
	if (p <= m)
        update(p , sc , lson);
	else
        update(p , sc , rson);
	PushUP(rt);
}


int query(int L,int R,int l,int r,int rt) //最大值
{
	if (L <= l && r <= R)
	{
		return MAX[rt];
	}
	int m = (l + r) >> 1;
	int ret = 0;
	if (L <= m)
        ret = max(ret , query(L , R , lson));
	if (R > m)
        ret = max(ret , query(L , R , rson));
	return ret;
}
int main()
{
    int n, m;
    while(~scanf("%d", &n))
    {
        int l, r;
        scanf("%d", &m);
        build(1, n, 1);
        while(m--)
        {
            char op[2];
            scanf("%s%d%d", op, &l, &r);
            if (op[0] == 'Q')
                printf("%d\n", query(l, r, 1, n, 1));
            else
                upda
                te(l , r, 1, n, 1);
        }
    }
}
