#include <iostream>
#include <cstdio>
using namespace std;
const int MAX=550000;
int p[MAX],rank[MAX],color=0,degree[MAX];
typedef struct node
{
    int key;
    struct node *next[26];
}Trie;
Trie *root;
Trie* NEW()
{
    int i;
    Trie *p;
    p=(Trie*)malloc(sizeof(Trie));
    p->key=-1;
    for (i=0;i<26;i++)
    p->next[i]=0;
    return p;
}
int insert(Trie *root,char *ch)
{
    int i;
    Trie *p=root;
    for (i=0;ch[i]!='\0';i++)
    {
        if (p->next[ch[i]-'a']==0)
        p->next[ch[i]-'a']=NEW();
        p=p->next[ch[i]-'a'];
    }
    if (p->key==-1)
    {
        p->key=++color;
    }
    return p->key;
}
void make_set(int x)
{
    p[x]=x;
    rank[x]=0;
}
int find(int x)
{
    if (x!=p[x])
    p[x]=find(p[x]);
    return p[x];
}
void Union(int x,int y)
{
    int a,b;
    a=find(x);
    b=find(y);
    if (a==b) return;
	if (rank[a]>rank[b])
	{
		p[b]=a;
	}
	else
	{
		if (rank[a]==rank[b])
		{
			rank[b]++;
		}
		p[a]=b;
	}

}
int main()
{
    int i,n,m,sum;
    char str1[11],str2[11];
    for (i=0;i<MAX;i++)
    make_set(i);
    root=NEW();
    while (scanf("%s %s",str1,str2)!=EOF)
    {
        n=insert(root,str1);
        m=insert(root,str2);
        degree[n]++;
        degree[m]++;
        Union(find(n),find(m));
    }
    sum=0;
    for (i=1;i<color;i++)
    if (degree[i]%2)
    sum++;
    if (sum>=3)
    printf("Impossible\n");
    else
    {
        for (i=2;i<color;i++)
        if (find(i)!=find(1))
        {
            printf("Impossible\n");
            break;
        }
        printf("Possible\n");
    }
}
