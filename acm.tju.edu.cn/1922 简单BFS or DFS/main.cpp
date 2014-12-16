#include <iostream>
#include <string>
using namespace std;
int m, n, Count;
char s[25][25];
int map[25][25];
int x[8]=
{
    -1,  0,
     1, -1,
     1, -1,
     0,  1
};
int y[8]=
{
     1,  1,
     1,  0,
     0, -1,
    -1, -1
};
int xx[4]=
{
     1, -1,
     0,  0
};
int yy[4]=
{
     0,  0,
     1, -1
};
int good(int i, int j)
{
    if(i >= 0 && i < m && j >= 0 && j < n)
    return 1;

    else
    return 0;
}

void dfs(int i, int j)
{
    int k, tx, ty;
    map[i][j] = 1;
    for(k = 0; k < 4; k++)
    {
        tx = i + xx[k];
        ty = j + yy[k];

        if(good(tx, ty) == 0 || s[tx][ty] == '.')
        Count++;
    }
    for(k = 0;k < 8; k++)
    {
        tx = i + x[k];
        ty = j + y[k];
        if(good(tx, ty) == 1 && s[tx][ty] == 'X' && map[tx][ty] == 0)
        dfs(tx, ty);
    }
}
int main()
{
    int x, y, i;
    while(cin>>m>>n>>x>>y)
    {
        if(m==0 && n==0 && x==0 && y==0)
        break;

        x--;
        y--;
        for(i = 0; i < m; i++)
        cin>>s[i];

        memset(map, 0, sizeof(map));

        Count = 0;
        dfs(x, y);

        cout<<Count<<endl;
    }
}
