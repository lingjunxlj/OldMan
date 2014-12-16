#include <stdlib.h>
#include <stdio.h>
int t[16][3];
int now[3];
int i, j;
long long min, d;
int main()
{
     for (i = 0; i < 16; i++)
       {
           scanf("%d %d %d", &t[i][0], &t[i][1], &t[i][2]);
       }
       while (scanf("%d %d %d", &now[0], &now[1], &now[2]) != -1)
       {
            if (now[0] == -1)
            break;
            min = 195075;
            j = 0;
            for (i = 0; i < 16; i++)
            {
                d = (long) (t[i][0] - now[0]) * (t[i][0] - now[0]) + (t[i][1] - now[1]) * (t[i][1] - now[1]) + (t[i][2] - now[2]) * (t[i][2] - now[2]);
                if (d < min)
                {
                    min = d;
                    j = i;
                    if (d == 0)
                    break;
                }
            }
            printf("(%d,%d,%d) maps to (%d,%d,%d)\n", now[0], now[1], now[2], t[j][0], t[j][1], t[j][2]);
        }
}
