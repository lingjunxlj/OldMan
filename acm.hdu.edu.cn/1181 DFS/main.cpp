#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct node
{
    char st;
    char ed;
}word[1000];
bool fg[1000];
int flag;
int n;
void dfs(char ch)
{
    if (ch == 'm')
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (word[i].st == ch && !fg[i])
        {
            fg[i] = 1;
            dfs(word[i].ed);
            fg[i] = 0;
        }
    }
    return;
}
int main()
{
    char str[100];
    while(scanf("%s", str)!= EOF)
    {
        n = 0;
        memset(fg, 0, sizeof(fg));
        while(strcmp(str,"0") != 0)
        {
            word[n].st = str[0];
            word[n].ed = str[strlen(str) - 1];
            n++;
            scanf("%s", str);
        }
        flag = 0;
        dfs('b');
        if (flag)
            printf("Yes.\n");
        else
            printf("No.\n");
    }
}
