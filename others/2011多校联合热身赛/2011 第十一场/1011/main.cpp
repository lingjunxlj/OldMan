#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL(x)	 ((x)<<1)
#define RR(x)	 ((x)<<1|1)
struct Seg_Tree{
	int left,right;
	int cval,lval,rval;
	int st;
	int mid() {
		return (left+right)>>1;
	}
	void doit() {
		cval = lval = rval = st ? 0 : dis();
	}
	int dis() {
		return (right - left + 1);
	}
}tt[150000];

void build(int l,int r,int idx)
{
	tt[idx].left = l;
	tt[idx].right = r;
	tt[idx].st = -1;
	tt[idx].cval = tt[idx].lval = tt[idx].rval = tt[idx].dis();
	if(l == r)	return ;
	int mid = tt[idx].mid();
	build(l,mid,LL(idx));
	build(mid+1,r,RR(idx));
}

void update(int l,int r,int st,int idx) {
	if(tt[idx].left >= l && r >= tt[idx].right) {
		tt[idx].st = st;
		tt[idx].doit();
		return ;
	}
	if(tt[idx].st != -1) {
		tt[LL(idx)].st = tt[RR(idx)].st = tt[idx].st;
		tt[LL(idx)].doit();
		tt[RR(idx)].doit();
		tt[idx].st = -1;
	}
	int mid = tt[idx].mid();
	if(l <= mid) update(l,r,st,LL(idx));
	if(mid < r)	update(l,r,st,RR(idx));

	tt[idx].cval = max( tt[LL(idx)].rval + tt[RR(idx)].lval , max(tt[LL(idx)].cval,tt[RR(idx)].cval) );
	tt[idx].lval = tt[LL(idx)].lval;
	tt[idx].rval = tt[RR(idx)].rval;
	if(tt[LL(idx)].cval == tt[LL(idx)].dis()) {
		tt[idx].lval += tt[RR(idx)].lval;
	}
	if(tt[RR(idx)].cval == tt[RR(idx)].dis()) {
		tt[idx].rval += tt[LL(idx)].rval;
	}
}

int query(int w,int idx)
{
	if(tt[idx].left == tt[idx].right && w == 1)
	{
		return tt[idx].left;
	}
	if(tt[idx].st != -1) {
		tt[LL(idx)].st = tt[RR(idx)].st = tt[idx].st;
		tt[LL(idx)].doit();
		tt[RR(idx)].doit();
		tt[idx].st = -1;
	}
	if(tt[LL(idx)].cval >= w)
	{
		return query(w,LL(idx));
	}
	else if(tt[LL(idx)].rval + tt[RR(idx)].lval >= w)
	{
		return tt[LL(idx)].right - tt[LL(idx)].rval + 1;
	}
	else if(tt[RR(idx)].cval >= w)
	{
		return query(w,RR(idx));
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n , m;
	while(scanf("%d%d",&n,&m) == 2)
	{
		build(1,n,1);
		while(m --)
		{
			char com[2];
			scanf("%s",com);
			if(com[0] == 'A')
			{
				int a;
				scanf("%d",&a);
				int s = query(a,1);
				printf("%d\n",s);
				if(s)
				{
					update(s,s+a-1,1,1);
				}
			}
			else
			{
				int a,b;
				scanf("%d%d",&a,&b);
				update(a,a+b-1,0,1);
			}
		}
	}
	return 0;
}
