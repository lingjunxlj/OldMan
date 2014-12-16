#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[5][5];
int n, maxnum;
bool judge(int x, int y)
{
    int i;
    for (i = x - 1; i >= 0; i--)
    {
        if (map[i][y] == 'X')
        break;
        if (map[i][y] == 'O')
        return 0;
    }
    for (i = y - 1; i >= 0; i--)
    {
        if (map[x][i] == 'X')
        break;
        if (map[x][i] == 'O')
        return 0;
    }
    return 1;
}
void dfs(int a, int num)
{
    int r, c;
    if (a == n * n)
    {
        if (num > maxnum)
            maxnum = num;
    }
    else
    {
       r = a / n;
       c = a % n;
       if (map[r][c] == '.' && judge(r, c))
       {
           map[r][c] = 'O';
           dfs(a + 1,num + 1);
           map[r][c] = '.';
       }
       dfs(a + 1,num);
    }
}
int main()
{
    while (cin>>n,n)
    {
        int i, j;
        for (i = 0; i < n; i++)
        cin>>map[i];

        maxnum = 0;
        dfs(0,0);
        cout<<maxnum<<endl;



    }
}
