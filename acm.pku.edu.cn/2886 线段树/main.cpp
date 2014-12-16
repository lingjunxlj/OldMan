#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int atPrm[100] =
{
    1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,
    5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,
    110880,166320,221760,277200,332640,498960
};
int d_num[100] =
{
    1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,
    96,100,108,120,128,144,160,168,180,192,200
};
struct ltreetype
{
    int l, r, m;
    int num;
}ltree[500000*8];
struct node
{
    char name[20];
    int m;
}a[600010];
int n, s;
void Build(int nowat, int tl, int tr)
{
    ltree[nowat].l = tl;
    ltree[nowat].r = tr;
    ltree[nowat].m = (tr + tl) / 2;
    ltree[nowat].num = tr - tl + 1;
    if(tl < tr)
    {
        Build(nowat*2, tl, ltree[nowat].m);
        Build(nowat*2 + 1, ltree[nowat].m + 1, tr);
    }
}
void del(int nowat, int tw)
{
    --ltree[nowat].num;
    if(ltree[nowat].l < ltree[nowat].r)
    {
        if(tw <= ltree[nowat].m)
            del(nowat*2, tw);
        else
            del(nowat*2 + 1, tw);
    }
}
int findcode(int tcode)
{
    int i = 1, sum = 0;
    while(ltree[i].l < ltree[i].r)
    {
        if(sum + ltree[i*2].num < tcode)
        {
            sum += ltree[i*2].num;
            i = i * 2 + 1;
        }
        else
            i = 2 * i;
    }
    return ltree[i].l;
}

int main()
{
   int i;
   while(scanf("%d %d", &n, &s) != EOF)
   {
        for(i = 1; i <= n; i++)
            scanf("%s %d",a[i].name, &a[i].m);
        Build(1, 1, n);
        int i, j, k, m;
        k = 0;
        int c = 0;
        while(c <= 34 && atPrm[c] <= n)
                c++;
        c -= 1;
        for(i = 1; i <= atPrm[c]; i++)
        {
            if(i == 1)
            {
                k = (k + s - 1)%(n - i + 1);
                j = findcode(k+1);
            }
            else
            {
                if(m > 0)
                {
                    k = (k+m-1)%(n-i+1);
                    j = findcode(k+1);
                }
                else
                {
                    k = (k+m)%(n-i+1);
                    while(k < 0)
                        k += (n-i+1);
                    j = findcode(k+1);
                }
            }
            if(i == atPrm[c])
                printf("%s %d\n", a[j].name, d_num[c]);
            del(1, j);
            if(i != n)
                k = k % (n - i);
            m = a[j].m;
        }
   }
   return 0;
}
