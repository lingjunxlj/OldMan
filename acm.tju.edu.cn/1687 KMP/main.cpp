#include <cstdio>
#include <string>
char str[1000010];
int next[1000010];
int main()
{
    int n,x=0;
    while (scanf("%d",&n),n)
    {
        getchar();
        x++;
        gets(str);
        int i= 0, j= -1; next[0]= -1;

        printf("Test case #%d\n",x);

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

        int s;
        for (i=1;i<=n;i++)
        {
            s=i-next[i];
            if (i%s == 0 && i/s > 1)
            printf("%d %d\n",i,i/s);
        }

        printf("\n");
    }
}
