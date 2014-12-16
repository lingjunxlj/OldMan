#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char text[100001],pat[100001];
int next[100001];
void get_next(char *s)
{

    int i=0,j=-1,len=strlen(s);
    next[0]=-1;
    while(i<len)
    {
        if(j==-1||s[i]==s[j])
        {
            i++;
            j++;
            next[i]=j;
        }
        else
            j=next[j];
    }
}
int main()
{
    int len,i,j;
    int t;
    scanf("%d", &t);
    getchar();
    while(t--)
    {
        scanf("%s", pat);
        len = strlen(pat);
        get_next(pat);
        int Min = len - next[len];

        printf("%d\n", next[len]);
        //printf("%d\n", Min);
        if (len == Min)
            printf("%d\n", Min);
        else if (len % Min == 0)
            printf("0\n");
        else
            printf("%d\n",Min - len % Min);

    }
    return 0;
}
