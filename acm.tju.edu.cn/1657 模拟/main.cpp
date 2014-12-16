#include <cstdio>
#include <string>
using namespace std;
char str[11];
int main()
{
    while( gets(str) != NULL )
    {
        int i, j, k;

        if(strlen(str) == 0 )
        {
            printf("\n");
            continue;
        }
        k = 1;
        int flag = 0;
        int num = 1;

        for( i=1 ; i<strlen(str) ; i++ )
        {
            if( str[i] != str[i-1] || num == 9  )
            {
                if( num == 1 )
                {
                    if( flag == 0 )
                    {
                        printf("1");
                        flag = 1;
                    }

                    if( str[i-1] == '1' )
                    printf("%c1", str[i-1]);

                    else
                    printf("%c", str[i-1]);

                }
                else
                {
                    printf("%d%c", num, str[i-1]);
                }
                num = 1;
            }
            else
            {
                if( flag )
                {
                    flag = 0;
                    printf("1");
                }
                num++;
            }
        }
        if( num == 1 )
        {
            if( flag != 1 )
            {
                flag = 1;
                printf("1");
            }
            if( str[i-1] == '1' )
            printf("%c1",str[i-1]);
            else
            printf("%c",str[i-1]);

            if( flag )
            {
                flag = 0;
                printf("1");
            }
        }
        else
        if( num > 1 )
        {
            if( flag )
            {
                flag = 0;
                printf("1");
            }
            printf("%d%c", num, str[i-1]);
        }
        printf("\n");
    }
}
