#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char map[11][11];
int num[11][11];
int n;
bool flag[11][11];
int dir[8][2] =
{
     1,  1,
     1,  0,
     0,  1,
    -1,  1,
     1, -1,
    -1,  0,
     0, -1,
    -1, -1
};
int main()
{
    int t, x = 1;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int sum = 0;
        memset(flag, 0, sizeof(flag));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                cin>>map[i][j];
                if (map[i][j] == '0')
                    num[i][j] = 0;
                if (map[i][j] != '@' && map[i][j] != '0')
                    num[i][j] = 1;
                if (map[i][j] == '@')
                {
                    flag[i][j] = 1;
                    num[i][j] = 0;
                }
                sum += num[i][j];

             }
             cout<<sum<<endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                int fg = 0;
                if (num[i][j] != 0)
                {
                    for(int k = 0; k < 8; k++)
                    {
                        int a = i + dir[k][0];
                        int b = j + dir[k][1];

                        if (num[a][b] == 0 && map[a][b] != '@')
                        {
                            fg = 1;
                            //flag[i][j] = 1;
                            break;
                        }
                    }
                }
                if (fg)
                    sum--;
            }



        printf("Case %d: %d\n", x++, sum);
    }
}
