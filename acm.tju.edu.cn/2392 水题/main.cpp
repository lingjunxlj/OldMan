#include <iostream>
using namespace std;
int cmp(const void *a,const void *b)
{
         if(((int *)a)[0] != ((int *)b)[0])
             return ((int *)a)[0] - ((int *)b)[0];
         else
             return ((int *)a)[1] - ((int *)b)[1];
}
int main()
{
    int i, x, y, flag = 0;
    int num[6][2];

    for (i = 0; i < 6; i++)
    {
        cin>>x>>y;

        if (x < y)
        {
            num[i][0] = x;
            num[i][1] = y;
        }
        else
        {
            num[i][0] = y;
            num[i][1] = x;
        }
    }

     qsort(num, 6, sizeof(int) * 2, cmp);

    if(num[0][0] == num[1][0] && num[1][0] == num[2][0]&&num[2][0] == num[3][0])
    {
        if(num[0][1] == num[1][1]&&num[1][1] == num[4][0]&&num[4][0] == num[5][0])
        {
            if(num[2][1] == num[3][1]&&num[3][1] == num[4][1]&&num[4][1] == num[5][1])
            flag = 1;
        }
    }
    if(flag)
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");
}

