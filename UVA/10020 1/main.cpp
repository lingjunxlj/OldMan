#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct segment
{
    int l, r;
}s[100010], ans[100010];


bool cmp(segment a,segment b)
{
    return((a.l<b.l)||(a.l==b.l)&&(a.r>b.r));
}
int main()
{
    int t;


    scanf("%d", &t);
    while(t--)
    {
        int n=0, m, x, y, j=1, tot=0;
        scanf("%d\n",&m);
        while(1)
        {
            scanf("%d %d\n",&x, &y);
            if ((x==0)&&(y==0))
                break;
            s[++n].l=x;
            s[n].r=y;
        }
        sort(s+1,s+n+1,cmp);
        for (int i=2;i<=n;i++)
            if ((s[i].l>s[j].l)&&(s[i].r>s[j].r))
                s[++j]=s[i];
        n=j;
        j=0;
        s[n+1].l=m+1;
        s[n+1].r=m+1;//加边界便于判断i==n的情况。

        for (int i=1;i<=n;i++)
        {
            if ((s[i+1].l>j)&&(s[i].l<=j))
            {
                j=s[i].r;
                ans[++tot]=s[i];
                if (s[i].r>=m)
                {
                    printf("%d\n",tot);
                    for (int k=1;k<=tot;k++)
                        printf("%d %d\n",ans[k].l,ans[k].r);
                    goto end;
                }
            }
        }
        printf("0\n");
        end:;
    }

    return 0;
}

