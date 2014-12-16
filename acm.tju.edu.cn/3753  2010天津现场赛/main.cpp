#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
char str[10010][34];
char temp[100];
double num[100];
int panduan[100];
const int sonnum=26,base='a';
struct Trie
{
    int num;
    bool terminal;
    struct Trie *son[sonnum];
};
Trie *NewTrie()
{
    Trie *temp=new Trie;
    temp->num=1;
    temp->terminal=false;
    for(int i=0;i<sonnum;++i)
        temp->son[i]=NULL;
    return temp;
}
void Insert(Trie *pnt,char *s,int len)
{
    Trie *temp=pnt;
    for(int i=0;i<len;++i)
    {
        if(temp->son[s[i]-base]==NULL)
            temp->son[s[i]-base]=NewTrie();
        else
            temp->son[s[i]-base]->num++;
        temp=temp->son[s[i]-base];
    }
    temp->terminal=true;
}
int um=0;
int Find(Trie *pnt,char *s,int len)
{
    Trie *temp=pnt;
    for(int i=0;i<len;++i)
        if(temp->son[s[i]-base]!=NULL)
        {

			temp=temp->son[s[i]-base];
			um=temp->num;

		}
        else
            return 0;
    return um;
}
int ten(int panduan[])
{
    int i = 8;
    int ans = 0, k = 1;
    while (i--)
    {
        ans += k * panduan[i];
        k *= 2;
    }
    return ans;
}
int main()
{
    int n, m;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        Trie *head = NewTrie();

        for (int i = 0; i < n; i++)
        {
            cin>>str[i];
            Insert(head, str[i], strlen(str[i]));
        }
        int x;
        int ans = 0;
        while (m--)
        {
            int top = 0;
            cin>>x;
            um = 0;
            while(x--)
            {
                memset(panduan, 0, sizeof(panduan));
                double min = 0x7fff, max = 0;
                for (int j = 0; j < 8; j++)
                {
                    cin>>num[j];
                    if (min > num[j])
                        min = num[j];
                    if (max < num[j])
                        max = num[j];
                }
                for (int k = 0; k < 8; k++)
                {
                    if(abs(num[k] - min) < abs(max - num[k]))
                        panduan[k] = 0;
                    if(abs(num[k] - min) > abs(max - num[k]))
                        panduan[k] = 1;
                }
                temp[top++] = ten(panduan);

            }
            ans += Find(head, temp, top);
        }
        printf("%d\n", ans);
    }
}
