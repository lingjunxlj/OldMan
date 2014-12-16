#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;
#define MAXN 100010
struct node
{
    int left, right, mid, len;
    int right0, left0, max0, count0;
    int right1, left1, max1, count1;
    bool fill0, fill1, chg;
};
node tree[MAXN*4];
int n, m, p[MAXN];
void updata(int i)
{
    tree[i].count0 = tree[i*2].count0 + tree[i*2+1].count0;
    tree[i].count1 = tree[i*2].count1 + tree[i*2+1].count1;
    tree[i].left0  = tree[i*2].left0==tree[i*2].len?tree[i*2].left0+tree[i*2+1].left0:tree[i*2].left0;
    tree[i].left1  = tree[i*2].left1==tree[i*2].len?tree[i*2].left1+tree[i*2+1].left1:tree[i*2].left1;
    tree[i].right0 = tree[i*2+1].right0==tree[i*2+1].len?tree[i*2+1].right0+tree[i*2].right0:tree[i*2+1].right0;
    tree[i].right1 = tree[i*2+1].right1==tree[i*2+1].len?tree[i*2+1].right1+tree[i*2].right1:tree[i*2+1].right1;
    tree[i].max0   = max(tree[i*2].right0 + tree[i*2+1].left0,max(tree[i*2].max0,tree[i*2+1].max0));
    tree[i].max1   = max(tree[i*2].right1 + tree[i*2+1].left1,max(tree[i*2].max1,tree[i*2+1].max1));
}
void build(int l,int r,int i)
{
    tree[i].left = l;
    tree[i].right = r;
    tree[i].mid = (l + r) / 2;
    tree[i].len = (r - l);
    tree[i].fill0 = tree[i].fill1 = tree[i].chg = 0;
    if(l + 1 == r)
    {
        tree[i].count0 = tree[i].max0 = tree[i].right0 = tree[i].left0 = !p[l];
        tree[i].count1 = tree[i].max1 = tree[i].right1 = tree[i].left1 = p[l];
        return ;
    }
    int mid = (l + r) / 2;
    build(l, tree[i].mid, i*2);
    build(tree[i].mid, r, i*2+1);
    updata(i);
}
void fill0(int i)
{
    int lt = 2*i, rt = 2*i+1;
    tree[i].count0 = tree[i].max0 = tree[i].right0 = tree[i].left0 = tree[i].len;
    tree[i].count1 = tree[i].max1 = tree[i].right1 = tree[i].left1 = 0;
    tree[i].fill0 = false;
    if(tree[i].left + 1 == tree[i].right) return ;
    tree[lt].fill0 = tree[rt].fill0 = 1;
    tree[lt].fill1 = tree[rt].fill1 = 0;
    tree[lt].chg = tree[rt].chg = 0;
}
void fill1(int i)
{
    int lt = 2*i, rt = 2*i+1;
    tree[i].count0 = tree[i].max0 = tree[i].right0 = tree[i].left0 = 0;
    tree[i].count1 = tree[i].max1 = tree[i].right1 = tree[i].left1 = tree[i].len;
    tree[i].fill1 = false;
    if(tree[i].left + 1 == tree[i].right) return ;
    tree[lt].fill0 = tree[rt].fill0 = 0;
    tree[lt].fill1 = tree[rt].fill1 = 1;
    tree[lt].chg = tree[rt].chg = 0;
}
void chg(int i)
{
    int lt = 2*i, rt = 2*i+1;
    swap(tree[i].count0,tree[i].count1);
    swap(tree[i].max0,tree[i].max1);
    swap(tree[i].left0,tree[i].left1);
    swap(tree[i].right0,tree[i].right1);
    tree[i].chg = false;
    if(tree[i].left + 1 == tree[i].right) return ;
    tree[lt].chg ^= true;
    tree[rt].chg ^= true;
}
void down(int i)
{
    if(tree[i].fill0) fill0(i);
    if(tree[i].fill1) fill1(i);
    if(tree[i].chg) chg(i);
}
void change(int l,int r,int i,int op)
{
    down(i);
    if(l == tree[i].left && r == tree[i].right)
    {
        if(op == 0) tree[i].fill0 = 1;
        else if(op == 1) tree[i].fill1 = 1;
        else tree[i].chg ^= 1;
        down(i);
        return ;
    }
    if(r <= tree[i].mid) change(l,r,2*i,op);
    else if( l >= tree[i].mid) change(l,r,2*i+1,op);
    else
    {
        change(l,tree[i].mid,2*i,op);
        change(tree[i].mid,r,2*i+1,op);
    }
    down(i*2);
    down(i*2+1);
    updata(i);
}
int onenum(int l,int r,int i)
{
    down(i);
    if(l == tree[i].left && r == tree[i].right) return tree[i].count1;
    if(r <= tree[i].mid) return onenum(l,r,2*i);
    else if( l >= tree[i].mid) return onenum(l,r,2*i+1);
    else return onenum(l,tree[i].mid,2*i) + onenum(tree[i].mid,r,2*i+1);
}
int lonenum(int l,int r,int i)
{
    down(i);
    if(l == tree[i].left && r == tree[i].right)
        return tree[i].max1;
    if(r <= tree[i].mid)
        return lonenum(l,r,2*i);
    else if( l >= tree[i].mid)
        return lonenum(l,r,2*i+1);
    else
        return max(max(lonenum(l,tree[i].mid,2*i), lonenum(tree[i].mid,r,2*i+1)),
                   min(tree[2*i].right1,tree[i].mid-l) + min(tree[2*i+1].left1,r-tree[i].mid));
}
int main ( )
{
    int tcase, a, b, op;
    for(scanf("%d", &tcase);tcase--;)
    {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);
        build(0,n,1);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &op, &a, &b);
            if(op<=2) change(a,b+1,1,op);
            else if(op==3) printf("%d/n", onenum(a,b+1,1));
            else printf("%d/n", lonenum(a,b+1,1));
        }
    }
    return 0;
}
