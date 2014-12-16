#include <cstdio>
int main()
{
    int num, y, r, key;
    while(scanf("%d",&num) != EOF, num)
    {
        getchar();
        y = r = 0;
        while(num--)
        {
            key=getchar();
            if(key == 'Y')
                y++;
            else if(key == 'R')
                r++;
            else if(key == 'B')
            {
                if(r == 7)
                    printf("Red\n");
                else
                    printf("Yellow\n");
            }
            else if(key == 'L')
            {
                if(y == 7)
                    printf("Yellow\n");
                else
                    printf("Red\n");
            }
        }
    }
}
