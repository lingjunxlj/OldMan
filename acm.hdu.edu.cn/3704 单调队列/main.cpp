#include <cstdio>
struct node
{
    int pos,value;
} q[10000005];
int s,e;
int main()
{
    int n,a,b;
    while(scanf("%d%d%d",&n,&a,&b)!=EOF)
    {
        int total=a%b,t=a%b,i;
        s=e=-1;
        e++;
        q[e].pos=1;
        q[e].value=t;
        for(i=2; i<=n; i++)
        {
            t=((long long)t*(a%b))%b;
            while(e!=s&&q[e].value>=t) e--;
            q[++e].pos=i;
            q[e].value=t;
            while(s!=e&&q[s+1].pos<i-a)
                s++;
            total = ((long long)total*(q[s+1].value%b))%b;
        }
        printf("%d\n",total);
    }
    return 0;
}
