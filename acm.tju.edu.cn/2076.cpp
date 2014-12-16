#include <stdio.h>
#include <stdlib.h>
int main ()
{
	int x;
	int q;
	scanf ("%d",&x);
	if (x>0)
	{
	while (x--)
	{
		int n,i=1,q,sum=0;
		scanf ("%d",&n);
		if (n>=5&&n<=100)
		{
           while(i<=n)
              {
				  q=i*i;
                 if(q<=n)
                  sum++;
                  i++;
              }
		printf ("%d\n",sum);
	}
    }
		system("pause");
}
}

