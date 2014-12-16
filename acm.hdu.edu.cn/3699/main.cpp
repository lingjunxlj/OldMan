#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 100
char a[3][100];
int num[maxn];
bool mark[maxn];
int map[maxn];
int ans;
int n;
int change(char s[])
{
    if(num[map[s[0]]] == 0 && strlen(s) > 1)
        return -1;
    int x = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        int tmp = map[s[i]];
        x = x * 10 + num[tmp];
    }
    return x;
}
void dfs(int len)
{
    if(len == n)
    {
        int x = change(a[0]);
        int y = change(a[1]);
        int z = change(a[2]);
        if(x == -1 || y == -1 || z == -1)
            return ;
        if(x + y == z)
            ans++;
        if(x - y == z)
            ans++;
        if(x * y == z)
            ans++;
        if(y != 0)
            if(x % y == 0 && x / y == z)
                ans++;
        return ;
    }
    for(int i = 0; i < 10; i++)
    {
        if(!mark[i])
        {
            num[len] = i;
            mark[i] = 1;
            dfs(len + 1);
            mark[i] = 0;
        }
    }
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>a[0]>>a[1]>>a[2];
        n = 0;
        memset(mark, 0, sizeof(mark));
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < strlen(a[i]); j++)
            {
                if(mark[a[i][j]] == 0)
                {
                    mark[a[i][j]] = 1;
                    map[a[i][j]] = n++;
                }
            }
        ans = 0;
        memset(mark, 0, sizeof(mark));
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
