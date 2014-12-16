#include <stdio.h>
#include <string.h>
char map[11][11];
int used[11][11];
int main()
{
    int col, row, step, i, j, Pos_X, Pos_Y, k, lcnt, scnt;
    char dir;
    while(scanf("%d %d %d", &row, &col, &step) != EOF)
    {
      if(row == 0 && col == 0 && step == 0)
      break;

      for(i = 1; i <= row; i++)
      {
        scanf("%s", map[i]);
      }
      memset(used, 0, sizeof(used));
      used[1][step-1] = 1;
      Pos_X = 1;
      Pos_Y = step - 1;
      dir = map[Pos_X][Pos_Y];

      k = 2;
      scnt = 1;
      lcnt = 0;

      while(Pos_X >= 1 && Pos_X <= row && Pos_Y >= 0 && Pos_Y < col)
      {
        if(dir == 'N')
        Pos_X--;
        if(dir == 'S')
        Pos_X++;
        if(dir == 'E')
        Pos_Y++;
        if(dir == 'W')
        Pos_Y--;

        if(used[Pos_X][Pos_Y])
        {
            lcnt = k-used[Pos_X][Pos_Y];
            scnt -= lcnt;
            break;
        }
        else
        {
            used[Pos_X][Pos_Y] = k;
            k++;
            dir = map[Pos_X][Pos_Y];
            scnt++;
        }
      }

      if(lcnt)
      printf("%d step(s) before a loop of %d step(s)\n", scnt, lcnt);
      else
      printf("%d step(s) to exit\n", scnt-1);

    }
}
