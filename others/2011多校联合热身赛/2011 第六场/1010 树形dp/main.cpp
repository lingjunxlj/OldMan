#include <stdio.h>
#include <vector>
#include <cstring>
using std::vector;

const long long int oo=1000000000000000000ll;
const int MAXN=100110;
int N;
long long int C[MAXN+1];
long long int A[MAXN-1],B[MAXN-1],L[MAXN-1];
vector<long long int> children[MAXN+1],length[MAXN+1];
long long int total_cow;
long long int cow[MAXN+1];
long long int cost[MAXN+1];
long long int answer;
void addedge(int u, int v, int val)
{
    edge[cnt].v = v;
    edge[cnt].adj = val;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void prepare(int root,int father_of_root=0)
{
     total_cow+=C[root];
     cow[root]+=C[root];
     for (int i=0;i<children[root].size();i++)
         if (children[root][i]!=father_of_root)
         {
            prepare(children[root][i],root);
            cow[root]+=cow[children[root][i]];
            cost[root]+=cost[children[root][i]]+cow[children[root][i]]*length[root][i];
         }
}
void get_answer(int root,int father_of_root=0)
{
     if (cost[root]<answer) answer=cost[root];
     for (int i=0;i<children[root].size();i++)
         if (children[root][i]!=father_of_root)
         {
            cost[children[root][i]]=cost[root]+(total_cow-cow[children[root][i]]*2)*length[root][i];
            get_answer(children[root][i],root);
         }
}
void print(long long int long_long_int)
{
     if (long_long_int>=10)
        print(long_long_int/10);
     printf("%d",int(long_long_int%10));
}

int main()
{
    while(scanf("%d", &N) != EOF)
    {
        total_cow = 0;
        for (int i = 0; i<=100110;i++)
        {
            children[i].clear();
            length[i].clear();
        }

        memset(cost, 0, sizeof(cost));
        memset(cow, 0, sizeof(cow));

        for (int i = 1; i<=N;i++)
            scanf("%d",&C[i]);
        for (int i=0;i<N-1;i++)
            scanf("%d %d %d",&A[i],&B[i],&L[i]);

        for (int i=0;i<N-1;i++)
        {
            children[A[i]].push_back(B[i]);
            children[B[i]].push_back(A[i]);
            length[A[i]].push_back(L[i]);
            length[B[i]].push_back(L[i]);
        }
        int leaf;
        for (int i=1;i<=N;i++)
            if (children[i].size()==1)
            {
               leaf=i;
               break;
            }
        prepare(leaf);
        answer=oo;
        get_answer(leaf);

        printf("%lld\n",answer); //for Windows


    }
    return 0;
}
