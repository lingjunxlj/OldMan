#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[12][12];
int n;
int dir[8][2]=
{
    {-1,0},
    {1,0},
    {0,-1},
    {0,1},
    {-1,-1},
    {-1,1},
    {1,-1},
    {1,1}
};
void dfs(int x, int y)
{

    if (map[x][y] == '0')
    {
        map[x][y] = '@';
        int xx, yy;
        for (int i = 0; i < 8; i++)
        {
            xx = x + dir[i][0];
            yy = y + dir[i][1];
            if (xx >= 0 && yy >= 0 && xx < n && yy < n )
            {
                dfs(xx, yy);
            }
        }
    }
    else
        map[x][y] = '@';
}

int main()
{
    int t, h = 1;
    cin>>t;
    while(t--)
    {
        cin>>n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                 cin>>map[i][j];
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                    if (map[i][j] == '0')
                    {
                        ans++;
                        dfs(i, j);
                    }
                    //else if (map[i][j] != '@')
                        //ans++;
            }

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (map[i][j] != '@')
                        ans++;
        printf("Case %d: %d\n", h++, ans);
    }

}

