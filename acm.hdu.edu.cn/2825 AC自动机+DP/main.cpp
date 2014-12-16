#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define key 20090717
char ss[20];
int dp[30][125][1050];
struct tree
{
    tree *fail,*next[26];
    int f,d;
}*root,*p,*q,*r;
tree arr[10001];
tree *que[10001];
int ind;
void newn()
{
    arr[ind].f = 0;
    arr[ind].d = ind;
    for (int i=0;i<26;i++) arr[ind].next[i] = 0;
    arr[ind].fail = NULL;
    return;
}
void insert(char ch[],int w)
{
    p=root;
    int i=0,tmp;
    while (ch[i])
    {
        tmp=ch[i]-'a';
        if (p->next[tmp]==0)
        {
            newn();
            p->next[tmp]=&arr[ind++];
        }
        p=p->next[tmp];
        i++;
    }
    p->f = 1<<w;
    // printf("%d\n",p->f);
}
inline void get_fail()
{
    tree *q;
    p=root;
    p->fail=root;
    int open=-1,close=-1,i;
    for (i=0;i<26;i++)
    {
        if (p->next[i]==0) p->next[i]=root;
        else
        {
            p->next[i]->fail=root;
            open++;
            que[open]=p->next[i];
        }
    }
    while (close<open)
    {
        close++;
        q=que[close];
        for (i=0;i<26;i++)
        {
            if (q->next[i]==0)
            {
                q->next[i]=q->fail->next[i];
            }
            else
            {
                q->next[i]->f = (q->next[i]->f)|(q->fail->next[i]->f);
                q->next[i]->fail=q->fail->next[i];
                open++;
                que[open]=q->next[i];
            }
        }
    }
    return;
}
int main()
{
    int n,m,k,tt,tmp,sum,cc,dd;
    int x,y,z,i,j;
    while (scanf("%d%d%d",&n,&m,&k))
    {
        if (n==0&&m==0&&k==0)
            break;
        ind = 0;
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = 1;
        newn();
        root = &arr[ind++];
        for (i=1;i<=m;i++)
        {
            scanf("%s",&ss);
            insert(ss,i-1);
        }
        get_fail();
        arr[0].f = 0;
        tree *p,*q;
        for (i=0;i<n;i++)
        {
            for (j=0;j<ind;j++)
            {
                for (y=0;y<(1<<m);y++)
                {
                    if (dp[i][j][y]==0) continue;
                    for (x=0;x<26;x++)
                    {
                        p = q = &arr[j];
                        if (p->next[x])
                            p = p->next[x];
                        else
                        {
                            while (p->next[x]==p->fail->next[x]&&p!=root)
                                p = p->fail;
                            if (p->next[x]!=p->fail->next[x])
                                p = p->next[x];
                        }
                        dp[i+1][p->d][y|p->f] = (dp[i+1][p->d][y|p->f] + dp[i][j][y])%key;
                    }
                }
            }
        }
        sum = 0;
        for (i=0;i<ind;i++)
        {
            for (j=0;j<(1<<m);j++)
            {
                cc = j;
                dd = 0;
                while (cc!=0)
                {
                    dd+=cc%2;
                    cc = cc>>1;
                }
                if (dd >= k)
                {
                    sum = (sum+dp[n][i][j])%key;
                }
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
