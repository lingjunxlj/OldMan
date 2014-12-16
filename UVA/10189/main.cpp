#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1010;
int n, m, t;
char map[MAXN][MAXN];
int ans[MAXN][MAXN];
int dir[8][2]=
{
      0,  1,
      0, -1,
      1,  0,
      1,  1,
      1, -1,
     -1, -1,
     -1,  0,
     -1,  1
};
int main()
{
    t = 0;
    while(cin>>n>>m)
    {

        if (n == 0 && m == 0)
            break;
        if (t)
           cout<<endl;
        t++;
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i++)
            cin>>map[i];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == '*')
                    continue;

                for (int k = 0; k < 8; k++)
                    if (map[i + dir[k][0]][j + dir[k][1]] == '*')
                        if ((i + dir[k][0]) >= 0 && (i + dir[k][0]) < n && (j + dir[k][1]) >= 0 && (j + dir[k][1]) < m)
                            ans[i][j]++;

            }
        printf("Field #%d:\n", t);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (map[i][j] == '*')
                    cout<<'*';
                else
                    cout<<ans[i][j];
            cout<<endl;
         }



    }

}
