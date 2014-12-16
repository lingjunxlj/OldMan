#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int direct[8][2] =
{
     -1,  0,
     -1,  1,
      0,  1,
      1,  1,
      1,  1,
     -1,  0,
     -1, -1,
     -1,  0
};
struct node
{
    int x;
    int y;
}queue[1000];
int main()
{
    int m,n,i,j,k;
    char map[10][10];
    int mark[10][10];
    while(cin>>m>>n && (m||n))
    {
        int length = 0, area = 0, f = 0, r = 0, num = 0;
        memset(map, '.', sizeof(map));
        memset(mark, 0, sizeof(mark));

        for(i = 1; i <= m; i++)
            for(j = 1; j <= n; j++)
                cin>>map[i][j];

        for(i = 1; i <= m; i++)
            for(j = 1; j <= n; j++)
            {
                if(map[i][j] == 'X' && mark[i][j] == 0)
                {
                    mark[i][j] = 1;
                    area++;
                    queue[r].x = i;
                    queue[r].y = j;
                    r++;
                    while(f != r)
                    {
                        int x11 = queue[f].x;
                        int y11 = queue[f].y;
                        f++;
                        for(k = 0; k < 8; k++)
                        {
                            int x1 = i + direct[k][0];
                            int y1 = j + direct[k][1];

                            if(map[x1][y1] == 'x' && mark[x1][y1] == 0)
                            {
                                mark[x1][y1] = 1;
                                area++;

                                queue[r].x = x1;
                                queue[r].y = y1;

                                r++;
                            }
                            else if(map[x1][y1] == '.' && mark[x1][y1] == 0)
                            {
                                mark[x1][y1] = 1;
                                if(x1 == i || y1 == j)
                                    length++;
                            }
                        }
                    }
                    num  += length / area;
                }
            }

            if(num <= (m * n) / 4)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
    }
    return 0;
}
