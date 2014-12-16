#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 2008000
map<string, int> mp;
string aa[5115];
map<int, string> mp1;
int hash[5115];
int ans[5111];

struct Edge
{
	int v, next,id;
	Edge(){}
	Edge(int a, int b, int c):v(a), next(b),id(c){}
}edge[400080];
int size,cnt, head[MAX];
inline void initg( )
{
	mp.clear();
	size = 0;
	cnt = 1;
	memset(edge, 0, sizeof(edge));
	memset( head, -1, sizeof( head ) );
}
inline void add_edge( int u, int v,int id )
{
	edge[size] = Edge( v, head[u], id );
	head[u] = size++;
	edge[size] = Edge( u, head[v], id );
	head[v] = size++;
}
int main()
{
    int t, x = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        initg();
        printf("Case %d:\n", x++);
        string a,b;
        for (int i = 0 ; i < n; i++)
        {
            cin>>a>>b;
            if (mp.find(a) == mp.end())
            {
                mp[a] = cnt++;

            }

            mp1[mp[a]] = a;
            //cout<<mp1[mp[a]]<<endl;


            if (mp.find(b) == mp.end())
            {
                mp[b] = cnt++;

            }
            mp1[mp[b]] = b;
            //cout<< mp1[mp[b]]<<endl;
            add_edge(mp[a], mp[b], i);

        }
        while(m--)
        {
            memset(hash,0,sizeof(hash));
            memset(ans, 0, sizeof(ans));
            char str[100];
            scanf("%s", str);
            int v;
            for (int i = head[mp[str]]; i != -1; i = edge[i].next)
                hash[edge[i].v] = 1;
            for (int i = head[mp[str]]; i != -1; i = edge[i].next)
            {

                v = edge[i].v;

                if (v == mp[str])
                    continue;
                //cout<<v<<"   "<<mp1[v]<<endl;
                for (int j = head[v]; j != -1; j = edge[j].next)
                {
                    if (hash[edge[j].v])
                        continue;
                    if (edge[j].v == mp[str])
                        continue;
                    //cout<<"j "<<edge[j].v<<"   "<<mp1[edge[j].v]<<endl;
                    ans[edge[j].v]++;
                }
            }
            int Max = 0;
            int s = 0;
            for (int i = 1 ; i < cnt; i++)
                if (ans[i] > Max)
                {
                    Max = ans[i];
                    s = i;
                }

            //printf("Max = %d\n", Max);
            int saa = 0;
            for (int i = 1 ; i < cnt; i++)
                if (ans[i] == Max && Max != 0)
                {
                    aa[saa++] = mp1[i];
                }


            if (saa > 0)
            {
                sort(aa, aa + saa);

                for (int i = 0 ; i < saa - 1; i++)
                {
                    cout<<aa[i];
                    printf(" ");
                    //cout<<aa[i];
                }
                cout<<aa[saa - 1];
                printf("\n");
            }
           else
                printf("-\n");

        }
    }
}
