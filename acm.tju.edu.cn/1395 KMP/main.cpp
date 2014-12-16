#include <cstdio>
#include <string>
char str[1000010];
int next[1000010];
int main()
{
    while (gets(str),str[0]!='.')
    {
        int i= 0, j= -1; next[0]= -1;

        while( str[i] )
        {
            if( j== -1 || str[i]== str[j] )
            {
                ++i,++j;
                next[i]= j;
            }
            else j= next[j];
        }

        int len= strlen(str);
        i= len- j;

        if( len% i== 0 )
        printf("%d\n",len/i);
        else
        printf("1\n");

    }
}
