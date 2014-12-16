#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char maze[61][61];
    int i, m, n, x, y;
    char commands, orientation;

    scanf("%d %d", &m, &n);
    {
        getchar();

        for(i = 1; i <= m; i++)
        gets(maze[i]);

        scanf("%d %d", &x, &y);

        orientation='N';
        y--;
        while(cin>>commands)
        {
            if (commands == 'Q')
            break;

            if(commands=='R')
            {
                if(orientation=='N')
                    orientation='E';

                else if(orientation=='E')
                    orientation='S';

                else if(orientation=='S')
                    orientation='W';

                else if(orientation=='W')
                    orientation='N';
            }
            else if(commands=='L')
            {
                if(orientation=='N')
                    orientation='W';

                else if(orientation=='E')
                    orientation='N';

                else if(orientation=='S')
                    orientation='E';

                else if(orientation=='W')
                    orientation='S';
            }
            else if(commands=='F')
            {
                if(orientation=='N')
                {
                    if(x - 1 >= 0 && maze[x - 1][y] == ' ')
                        x--;
                }

                else if(orientation == 'E')
                {
                    if(y + 1 <= n - 1 && maze[x][y + 1] == ' ')
                        y++;
                }

                else if(orientation == 'S')
                {
                    if(x + 1 <= m && maze[x + 1][y] == ' ')
                        x++;
                }

                else if(orientation == 'W')
                {
                    if(y - 1 >= 0 && maze[x][y - 1] == ' ')
                        y--;
                }
            }
        }
        printf("%d %d %c\n", x, y + 1, orientation);
    }
    return 0;
}
