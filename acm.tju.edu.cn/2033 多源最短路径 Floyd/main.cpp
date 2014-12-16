#include <iostream>
#include <string>
using namespace std;
const int Max = 100;
const int INF = 20;
int map[Max][Max];
int main()
{
    int x = 1;
    int n;
    int i, j, k, a, b;
    while (cin>>n)
    {
        if (n == 0)
        break;

        memset(map, INF, sizeof(map));
        map[1][1] = 0;
        a = 1;

        for (i = 0; i < n; i++)
        {
            cin>>b;
            map[a][b] = map[b][a] = 1;
        }

        for (j = 2; j <= 19; j++)
        {
            map[j][j] = 0;
            cin>>n;
            for (i = 0; i < n; i++)
            {
                cin>>b;
                map[j][b] = map[b][j] = 1;
            }
        }

        for (k = 1; k <= 20; ++k)
            for (i = 1; i <= 20; ++i)
                for (j = 1; j <= 20; ++j)
                    if (map[i][k]+map[k][j] < map[i][j])
                        map[i][j] = map[i][k]+map[k][j];

        cin>>n;
        printf("Test Set #%d\n",x++);
        for (i = 1; i <= n; ++i)
        {
            cin>>a>>b;
            printf("%d to %d: %d\n", a, b, map[a][b]);
        }
        cout<<endl;
    }
}
