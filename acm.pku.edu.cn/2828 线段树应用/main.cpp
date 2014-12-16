#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[200002], val[200002], MAX[800040], ans[200002];
#define lson l , m , rt << 1
#define rson m + 1 , r , rt << 1 | 1
int id;
void build(int l,int r,int rt)
{
	MAX[rt] = r - l + 1;
	if (l == r)
        return ;
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
}
void update(int p,int l,int r,int rt)
{
	MAX[rt]--;
	if (l == r)
	{
		id = l;
		return ;
	}
	int m = (l + r) >> 1;
	if (MAX[rt<<1] >= p)
        update(p , lson);
	else
	{
	    p -= MAX[rt<<1];
	    update(p , rson);
    }
}
int main()
{
    int n;
    while(~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &num[i], &val[i]);
        build(1, n, 1);
        for (int i = n; i >= 1; i--)
        {
            update(num[i] + 1, 1, n, 1);
            ans[id] = val[i];
        }
        for(int i = 1; i <= n; i ++)
            printf("%d ", ans[i]);
        printf("\n");

    }

}
