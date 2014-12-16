/*
1.把所有要query的区间按右端点升序排，假设排序后的区间为[a1,b1] [a2,b2] …… [aQ,bQ]
2.线段树的附加信息val是[i,j]所在区间的不同数的和,
同时，如果[j+1,n]中存在某个数b与[i,j]之间的某个数相等,则val-=b
3.插入[1,b1]后查询[a1,b1],接着插入[b1+1,b2]查询[a2,b2],接着插入[b2+1,b3]查询[a3,b3]……
4.正确性：假设查询[a1,b1]时分解成[c1,d1]、[c2,d2],如果数b同时出现在两个区间，
那么在插入[c2,d2]中的b时需要删除[c1,d1]中的数b,因此不会重复计算b
*/
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define M 50010
#define N 200001
#define L(x) (x<<1)
#define R(x) ((x<<1)|1)
#define Mid(x,y) ((x+y)>>1)
typedef struct
{
	int lt;
	int rt;
	long long sum;
}SegT;

typedef struct talHash
{
	int ix, v;
	talHash *next;
}HashN;

typedef struct
{
	int r, l, ix;
}Pair;

SegT tr[M*4];
HashN *hash[M];
HashN MEM[M];
Pair pair[N];
int a[M], e;
long long ans[N], anst;
int Cmp(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}
int Key(int value)
{
	value += value;
	while(value >= M)
        value -= M;
	return value;
}
int AtHash(int value)
{
	HashN *cur;
	for(cur = hash[Key(value)]; cur; cur = cur -> next)
		if(cur->v == value)
            break;
	return cur?cur -> ix:0;
}
void HashInsert(int value, int ix)
{
	HashN *cur = &MEM[e++];
	cur->ix = ix;
	cur->v = value;
	cur->next = hash[Key(value)];
	hash[Key(value)] = cur;
}
void Create(int ix, int l, int r)
{
	tr[ix].lt = l;
	tr[ix].rt = r;
	tr[ix].sum = 0;
	if(l == r)
        return ;
	int mid = Mid(l,r);
	Create(L(ix), l, mid);
	Create(R(ix), mid + 1, r);
}
void Updata(int ix, int pos, int delta)
{
	int mid;
	if(tr[ix].lt == tr[ix].rt)
	{
		tr[ix].sum += delta;
		return ;
	}
	mid = Mid(tr[ix].lt, tr[ix].rt);
	if(pos <= mid)
        Updata(L(ix), pos, delta);
	else
        Updata(R(ix), pos, delta);
	tr[ix].sum = tr[L(ix)].sum + tr[R(ix)].sum;
}
void Query(int ix, int l,int r)
{
	int mid;
	if(tr[ix].lt == l &&tr[ix].rt==r)
	{
		 anst += tr[ix].sum;
		 return ;
	}
	mid = Mid(tr[ix].lt,tr[ix].rt);
	if(r <= mid)
        Query(L(ix), l, r);
	else if(l > mid)
        Query(R(ix), l, r);
	else
	{
		Query(L(ix),l,mid);
		Query(R(ix),mid+1,r);
	}
}
int main()
{
	int n, t, i, j, q;
	int preix;
	scanf("%d", &t);
	while(t--)
	{
		memset(hash, NULL, sizeof(hash));
		scanf("%d", &n);

		for(i = 1; i <= n; i++)
			scanf("%d", &a[i]);

		scanf("%d", &q);
		for(i = 0; i < q; i++)
		{
			scanf("%d %d",&pair[i].l, &pair[i].r);
			pair[i].ix = i;
		}

		qsort(pair, q, sizeof(pair[0]), Cmp);
		Create(1,1,n);

		for(i = 1 ,j = e = 0; i <= n;i++)
		{
			preix = AtHash(a[i]);
			if(preix)
                Updata(1, preix, -a[i]);
			HashInsert(a[i],i);
			Updata(1, i, a[i]);
			for(;j < q && pair[j].r == i; j++)
			{
				anst = 0;
				Query(1, pair[j].l, pair[j].r);
				ans[pair[j].ix] = anst;
			}
		}
		for(j = 0; j < q; j++)
			printf("%I64d\n", ans[j]);
	}
	return 0;
}
