#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char x[55];
int l,max1,ans;
bool mark;
struct node
{
	char d;
	node *next[26];
	bool flag;
};
void insert(node *t)
{
	for(int i=0;i<l;i++)
	{
		if(t->next[x[i]-'a']) t=t->next[x[i]-'a'];
		else
		{
			t->next[x[i]-'a']=new node;
			t->next[x[i]-'a']->flag=0;
			for(int j=0;j<26;j++)
			{
				t->next[x[i]-'a']->next[j]=NULL;
			}
			t->next[x[i]-'a']->d=x[i];
			t=t->next[x[i]-'a'];
		}
	}
}
void dfs(node *t,int c)
{
	int cnt=0,i;
	if(t)
	{
		for(i=0;i<26;i++)
			if(t->next[i]) cnt++;
		if(cnt==0)
		{
			if(c==max1&&!mark) {t->flag=1;mark=1;ans++;}
			else ans+=2;
			return ;
		}
		for(i=0;i<26;i++)
			if(t->next[i])
			{
				dfs(t->next[i],c+1);
				t->flag=t->flag||t->next[i]->flag;
			}
		if(c>0)
		{
			if(t->flag) ans++;
			else ans+=2;
		}
	}
}
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		node *root=new node;
		for(i=0;i<26;i++) root->next[i]=NULL;
		root->flag=0;
		max1=0;
		for(i=0;i<n;i++)
		{
			memset(x,0,sizeof(x));
			scanf("%s",x);
			l=strlen(x);
			max1=max(max1,l);
			insert(root);
		}
		ans=mark=0;
		dfs(root,0);
		ans+=n;
		printf("%d\n",ans);
	}
	return 0;
}
