#include<cstdio>
#include<cstring>
#include<cmath>
#define SIZE 1200
char list[SIZE][SIZE];
int num[10000000];
void fn(int size, int x, int y)
{
    if(size==1)
    {
        list[x][y] = 'X';
    }
    else
    {
        int d = size/3;
        fn(size/3,  x,               y);
        fn(size/3,  x,         y + 2*d);
        fn(size/3,  x + d,       y + d);
        fn(size/3,  x + 2*d,         y);
        fn(size/3,  x + 2*d,   y + 2*d);
    }
}
int main()
{
    int n;
    int size;
    while(scanf("%d", &n) && n!=-1)
    {
        memset(list, 0, sizeof(list));
        memset(num, 0, sizeof(num));
        size = (int)pow(3, (double)(n-1));
        fn(size,0,0);

        for (int i=0;i<size;i++)
        {
            for (int j=size-1;j>=0 && list[i][j]!='X';j--)
                list[i][j]='a';
        }
        for(int i = 0; i < size; i++)
        {
            num[i]=0;
            for(int j = 0; j < size; j++)
            {
                if (list[i][j]!='a')
                printf("%c", list[i][j]=='X' ? 'X' : ' ');
            }
            printf("\n");
        }
        printf("-\n");
    }
}
