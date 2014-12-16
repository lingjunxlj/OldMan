#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL(x)	 ((x)<<1)
#define RR(x)	 ((x)<<1|1)
struct Node
{
	int idx;
	int val;
	friend bool operator < (Node a,Node b)
	{
		if(a.val == b.val)
			return a.idx > b.idx;

		return a.val < b.val;
	}
};
struct Seg_Tree
{
	int left,right;
	Node node;
	int add;
	int calmid()
	{
		return (left+right)/2;
	}
}tt[3000001];

void build(int left,int right,int idx)
{
	tt[idx].left = left;
	tt[idx].right = right;
	tt[idx].add = 0;
	tt[idx].node.idx = left;
	tt[idx].node.val = 0;

	if(left == right)
		return ;

	int mid = tt[idx].calmid();
	build(left,mid,LL(idx));
	build(mid+1,right,RR(idx));
}

void update(int left,int right,int add,int idx)
{
	if(left <= tt[idx].left && right >= tt[idx].right)
	{
		tt[idx].node.val += add;
		tt[idx].add += add;
		return ;
	}
	if(tt[idx].add)
	{
		tt[LL(idx)].node.val += tt[idx].add;
		tt[RR(idx)].node.val += tt[idx].add;
		tt[LL(idx)].add += tt[idx].add;
		tt[RR(idx)].add += tt[idx].add;
		tt[idx].add = 0;
	}
	int mid = tt[idx].calmid();
	if(left <= mid)
        update(left,right,add,LL(idx));
	if(mid < right)
        update(left,right,add,RR(idx));

	tt[idx].node = max(tt[LL(idx)].node , tt[RR(idx)].node);
}

Node query(int left,int right,int idx)
{
	if(left == tt[idx].left && right == tt[idx].right)
	{
		return tt[idx].node;
	}
	if(tt[idx].add)
	{
		tt[LL(idx)].node.val += tt[idx].add;
		tt[RR(idx)].node.val += tt[idx].add;
		tt[LL(idx)].add += tt[idx].add;
		tt[RR(idx)].add += tt[idx].add;
		tt[idx].add = 0;
	}
	int mid = tt[idx].calmid();

	if(right <= mid)
		return query(left,right,LL(idx));

	 else if(left > mid)
		return query(left,right,RR(idx));

	 else
		return max(query(left,mid,LL(idx)) , query(mid+1,right,RR(idx)));

}

int main()
{
	int n , m ;
	int t, x= 1;
	cin>>t;
	while(t--)
    {
		scanf("%d%d",&n,&m);
		build(1, 1000001,1);
		printf("Case %d:\n", x++);
		for (int i = 1; i <= m; i++)
		{

				int a,b;
				scanf("%d%d",&a,&b);
				Node ret = query(a,b-1,1);
				if (ret.val < n)
				{
				    printf("%d ", i);

                    update(a,b-1,1,1);
				}

			}
			printf("\n\n");
		}
	}


