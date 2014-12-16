#include <stdio.h>
#include <stdlib.h>
int main ()
{
	float x;
	int n;
	while (1)
	{		
		scanf ("%f",&x);
		if (x==0.00||x<0.01||x>5.20)
		break;	
		float sum=0;
		if (x<0.5)
		{n=1;
		goto A;
	    }
	     for(n=1;;n++)
         {
            sum=sum+(float)1/(n+1);
            if(x-sum<0.001) break;
          }
					
	A:	printf ("%d card(s)\n",n);
	}
	system("pause");
}
