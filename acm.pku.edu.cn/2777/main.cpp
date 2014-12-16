#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define LL(x)	 ((x)<<1)
#define RR(x)	 ((x)<<1|1)
template<class T> inline T countbit(T n)	{return n?1+countbit(n&(n-1)):0;}
#define two(x)				(1<<(x))
struct Seg_Tree{
	int left,right;
	int col;
	bool cover;
	int calmid()
	{
		return (left+right)/2;
	}
}tt[300000];

void build(int left,int right,int idx)
{
	tt[idx].left = left;
	tt[idx].right = right;
	tt[idx].col = two(1);
	tt[idx].cover = true;
	if(left == right)
		return ;
	int mid = tt[idx].calmid();
	build(left,mid,LL(idx));
	build(mid+1,right,RR(idx));
}

void update(int left,int right,int c,int idx)
{
	if(left <= tt[idx].left && right >= tt[idx].right)
	{
		tt[idx].cover = true;
		tt[idx].col = two(c);
		return ;
	}
	if(tt[idx].cover)
    {
		tt[RR(idx)].col = tt[LL(idx)].col = tt[idx].col;
		tt[RR(idx)].cover = tt[LL(idx)].cover = true;
		tt[idx].cover = false;
	}
	int mid = tt[idx].calmid();
	if(left <= mid)
        update(left,right,c,LL(idx));
	if(mid < right)
        update(left,right,c,RR(idx));
	tt[idx].col = tt[LL(idx)].col | tt[RR(idx)].col;
}

int query(int left,int right,int idx)
{

	if(left == tt[idx].left && right == tt[idx].right)
		return tt[idx].col;

	if(tt[idx].cover)
	{
		tt[RR(idx)].col = tt[LL(idx)].col = tt[idx].col;
		tt[RR(idx)].cover = tt[LL(idx)].cover = true;
		tt[idx].cover = false;
	}
	int mid = tt[idx].calmid();

	if(right <= mid)
		return query(left,right,LL(idx));

	else if(mid < left)
		return query(left,right,RR(idx));

	else
		return query(left,mid,LL(idx)) | query(mid+1,right,RR(idx));

}

int main()
{
	int n,T,o;
	while(scanf("%d%d%d",&n,&T,&o) == 3)
	{
		build(1,n,1);
		while(o--)
		{
			char ch[2];
			scanf("%s",&ch);
			if(ch[0] == 'C')
			{
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				if(a > b)
                    swap(a,b);
				update(a,b,c,1);
			}
			else
			{
				int a,b;
				scanf("%d%d",&a,&b);
				if(a > b)
                    swap(a,b);
				printf("%d\n",countbit(query(a,b,1)));
			}
		}
	}
	return 0;
}
