#include <stdio.h>
int main()
{
    double n;
    while( scanf("%lf",&n) != EOF )
    {
        int s=0;
        while (1)
        {
            if (n<=18)
            break;
            n=n/18.0;

        }
        if(1<n&&n<=9)
        s=1;
        else if(n>9&&n<=18)
        s=0;
        printf(s ? "Stan wins.\n" : "Ollie wins.\n");
     }

}
