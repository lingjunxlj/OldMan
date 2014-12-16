#include <stdio.h>
#include <stdlib.h>
int main()
{
    double s;
    double n;
    scanf("%lf",&n);
    s=n;
    while(1)
    {
        scanf("%lf",&n);
        if(n==999)
        {
            printf("End of Output\n");
            break;
        }    
        printf("%.2lf\n",n-s);
        s=n;
    }

    system("pause");
	return 0;
}
