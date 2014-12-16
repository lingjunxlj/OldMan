#include <iostream>
#include <string>
using namespace std;
int main()
{
    char a[1000];
    int n, m, f, l, i, j;
    while(scanf("%s",a) != EOF)
    {
        if(a[0] == a[1])
        f = 0;
        else
        f = 1;
        l = strlen(a);
        if(f == 0)
        {
            for(i = 0, j = l - 1; i < j; i++, j--)
            printf("%c%c", a[i], a[j]);
        }
        else
        {
            for(i = 0; i < l/2; i++)
            printf("%c", a[0]);
            for(i = 0; i < l/2; i++)
            printf("%c", a[1]);
        }
        printf("\n");
    }
}
