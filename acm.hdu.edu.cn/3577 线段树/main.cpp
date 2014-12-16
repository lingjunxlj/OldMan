#include <cstdio>
#include <cmath>
#include <iostream>
#include <ctring>
using namespace std;
#define LL(x)	 ((x)<<1)
#define RR(x)	 ((x)<<1|1)
#define FF(i,n)	 for(int i = 0 ; i < n ; i ++)
struct Node{
	int idx;
	int val;
	friend bool operator < (Node a,Node b) {
		if(a.val == b.val) {
			return a.idx > b.idx;
		}
		return a.val < b.val;
	}
};
struct Seg_Tree {
	int left,right;
	Node node;
	int add;
	int calmid() {
		return (left+right)/2;
	}
}tt[300000];

void build(int left,int right,int idx) {
	tt[idx].left = left;
	tt[idx].right = right;
	tt[idx].add = 0;
	tt[idx].node.idx = left;
	tt[idx].node.val = 0;
	if(left == right) {
		return ;
	}
	int mid = tt[idx].calmid();
	build(left,mid,LL(idx));
	build(mid+1,right,RR(idx));
}

void update(int left,int right,int add,int idx) {
	if(left <= tt[idx].left && right >= tt[idx].right) {
		tt[idx].node.val += add;
		tt[idx].add += add;
		return ;
	}
	if(tt[idx].add) {
		tt[LL(idx)].node.val += tt[idx].add;
		tt[RR(idx)].node.val += tt[idx].add;
		tt[LL(idx)].add += tt[idx].add;
		tt[RR(idx)].add += tt[idx].add;
		tt[idx].add = 0;
	}
	int mid = tt[idx].calmid();
	if(left <= mid) update(left,right,add,LL(idx));
	if(mid < right) update(left,right,add,RR(idx));
	tt[idx].node = max(tt[LL(idx)].node , tt[RR(idx)].node);
}

Node query(int left,int right,int idx) {
	if(left == tt[idx].left && right == tt[idx].right) {
		return tt[idx].node;
	}
	if(tt[idx].add) {
		tt[LL(idx)].node.val += tt[idx].add;
		tt[RR(idx)].node.val += tt[idx].add;
		tt[LL(idx)].add += tt[idx].add;
		tt[RR(idx)].add += tt[idx].add;
		tt[idx].add = 0;
	}
	int mid = tt[idx].calmid();
	if(right <= mid) {
		return query(left,right,LL(idx));
	} else if(left > mid) {
		return query(left,right,RR(idx));
	} else {
		return max(query(left,mid,LL(idx)) , query(mid+1,right,RR(idx)));
	}
}

int main() {
	int n , m ;
	while(scanf("%d%d",&n,&m) == 2) {
		if(n == 0 && m == 0)	break;
		build(1,n,1);
		while(m --) {
			char com[2];
			scanf("%s",&com);
			if(com[0] == 'I') {
				int a,b,c;
				scanf("%d%d%d",&a,&b,&c);
				update(a,b,c,1);
			} else {
				int a,b;
				scanf("%d%d",&a,&b);
				Node ret = query(a,b,1);
				printf("%d\n",ret.val);
				update(ret.idx,ret.idx,-ret.val,1);
			}
		}
	}
	return 0;
}
