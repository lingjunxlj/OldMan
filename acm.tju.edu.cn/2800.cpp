#include <stdio.h>
#include <stdlib.h>
int main()
{
	int x;
	scanf ("%d",&x);
	while (x--)
	{
		int a,b,c,d,i;
		int m,n;		
		scanf ("%d",&a);
		if (a%2==1)
		{
			b=a*a;
			c=b;
			d=b;
			for (i=0;i<((a-1)/2);i++)
			{
				c=c-2;
				d=d+2;
			}
			printf ("%d %d\n",c,d);
		}
			else
			{
				b=a*a;
				m=b-1;
				n=b+1;
				for (i=0;i<a/2;i++)
				{
					m=m-2;
					n=n+2;
			     }
			printf ("%d %d\n",m+2,n-2);}			
		}
		system("pause");
}
		
