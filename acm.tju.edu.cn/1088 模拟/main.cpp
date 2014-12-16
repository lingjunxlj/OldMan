#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
    int x;
    int y;
    int nut;
}a[2550];
bool cmp (node p, node q)
{
    return p.nut > q.nut;
}
int main ()
{
    int dataset;
    scanf ("%d", &dataset);

    while ( dataset-- )
    {
        int m, n, k;
        scanf ("%d %d %d", &m, &n, &k);

        int field[52][52];
        int index = 0;

        for ( int i = 0; i < m; i++ )
        {
            for ( int j = 0; j < n; j++ )
            {
                scanf ("%d", &field[i][j]);

                if ( field[i][j] )
                {
                    a [index].nut = field[i][j];
                    a [index].x = i;
                    a [index].y = j;
                    index++;
                }
            }
        }

        sort (a, a + index, cmp);

        int totalNut = 0;
        int cur_x = 0;
        int cur_y = a[0].y;
        k--;

        for ( int i = 0; i < index; i++ )
        {
            int inCost = abs (cur_x - a [i].x) + abs (cur_y - a [i].y) + 1;
            int outCost = abs (0 - a [i].x) + 1;
            int tempCost = inCost + outCost;

            if ( tempCost <= k )
            {
                k -= inCost;
                cur_x = a [i].x;
                cur_y = a [i].y;
                totalNut += a [i].nut;
            }

            else
            break;
        }

        printf ("%d\n", totalNut);
    }

    return 0;
}
